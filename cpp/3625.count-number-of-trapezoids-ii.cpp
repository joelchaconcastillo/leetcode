#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long SCALE = 1e9;
    static const long long BIAS = 2000;

    long long hash_fraction(tuple<long long, long long> fraction) {
        auto [a, b] = fraction;
        long long gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        return (a + BIAS) + (b + BIAS) * SCALE;
    }

    long long slope(int x1, int y1, int x2, int y2) {
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        if (dx == 0) return hash_fraction({1, 0});
        if (dy == 0) return hash_fraction({0, 1});
        long long gcd = __gcd(dy, dx);
        dy /= gcd;
        dx /= gcd;
        if (dx < 0) dy = -dy, dx = -dx;
        return hash_fraction({dy, dx});
    }

    long long getIntersection(long long x1, long long y1, long long x2, long long y2) {
        if (y1 == y2) {
            return hash_fraction({SCALE / 10, y1});
        }
        long long num = x1 * (y2 - y1) - y1 * (x2 - x1);
        long long den = y2 - y1;
        return hash_fraction({num, den});
    }

    pair<long long, long long> countTrapezoids2(unordered_map<long long, unordered_map<long long, long long>>& groupedByIntersection) {
        long long edgeCount = 0;
        for (auto& [intersection, groupedByLength] : groupedByIntersection) {
            for (auto& [length, count] : groupedByLength) {
                edgeCount += count;
            }
        }

        long long trapezoidCount = 0;
        for (auto& [intersection, groupedByLength] : groupedByIntersection) {
            long long count = 0;
            for (auto& [length, freq] : groupedByLength) {
                count += freq;
            }
            trapezoidCount += count * (edgeCount - count);
            edgeCount -= count;
        }

        unordered_map<long long, unordered_map<long long, long long>> groupedByLength;
        for (auto& [intersection, groupedByLen] : groupedByIntersection) {
            for (auto& [length, freq] : groupedByLen) {
                groupedByLength[length][intersection] += freq;
            }
        }

        long long parallelogramCount = 0;
        for (auto& [length, groupedByInter] : groupedByLength) {
            long long total = 0;
            for (auto& [intersection, freq] : groupedByInter) {
                total += freq;
            }
            for (auto& [intersection, freq] : groupedByInter) {
                parallelogramCount += freq * (total - freq);
                total -= freq;
            }
        }

        return {trapezoidCount - parallelogramCount, parallelogramCount};
    }

    int solve(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<long long, unordered_map<long long, unordered_map<long long, long long>>> freq;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];

                long long slope_key = slope(x1, y1, x2, y2);
                long long intersection = getIntersection(x1, y1, x2, y2);
                long long len = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

                freq[slope_key][intersection][len]++;
            }
        }

        long long trapezoidCount = 0;
        long long parallelogramCount = 0;

        for (auto& [slope_key, intersection_map] : freq) {
            auto [trapCount, paraCount] = countTrapezoids2(intersection_map);
            trapezoidCount += trapCount;
            parallelogramCount += paraCount;
        }

        return trapezoidCount + parallelogramCount / 2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        return solve(points);
    }
};

