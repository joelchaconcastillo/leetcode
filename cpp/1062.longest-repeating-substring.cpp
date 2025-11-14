class Solution {
public:


    int solve(string &s) {
	  int n = s.size();
          if (n <= 1) return 0;
          const long long mod1 = 1000000007LL;
          const long long mod2 = 1000000009LL;
          const long long base = 131;
          vector<long long> h1(n+1, 0), p1(n+1, 1);
          vector<long long> h2(n+1, 0), p2(n+1, 1);
          for (int i = 0; i < n; ++i) {
              h1[i+1] = (h1[i] * base + (unsigned char)s[i]) % mod1;
              p1[i+1] = (p1[i] * base) % mod1;
              h2[i+1] = (h2[i] * base + (unsigned char)s[i]) % mod2;
              p2[i+1] = (p2[i] * base) % mod2;
          }
          auto getHashPair = [&](int l, int r) -> unsigned long long {
              long long x1 = (h1[r+1] - h1[l] * p1[r-l+1]) % mod1;
              if (x1 < 0) x1 += mod1;
              long long x2 = (h2[r+1] - h2[l] * p2[r-l+1]) % mod2;
              if (x2 < 0) x2 += mod2;
              return ( (unsigned long long)x1 << 32 ) ^ (unsigned long long)x2;
          };
          int res = 0;
          for (int len = 1; len <= n; ++len) {
              unordered_map<unsigned long long, vector<int>> seen;
              seen.reserve(n - len + 1);
              for (int start = 0; start + len - 1 < n; ++start) {
                  int end = start + len - 1;
                  auto key = getHashPair(start, end);
                  if (seen.count(key)) {
                      bool matched = false;
                      for (int prevStart : seen[key]) {
                          if (s.compare(prevStart, len, s, start, len) == 0) {
                              matched = true;
                              break;
                          }
                      }
                      if (matched) res = max(res, len);
                  }
                  seen[key].push_back(start);
              }
          }
          return res;
    }
    int longestRepeatingSubstring(string s) {
	    return solve(s);
    }
};
