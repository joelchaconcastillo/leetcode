#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<string> path;
    unordered_map<string, vector<string>> parents;
    string beginWord; 

    void dfs(const string &node) {
        path.push_back(node);
        if (node == beginWord) {
            res.emplace_back(path.rbegin(), path.rend());
            path.pop_back();
            return;
        }
        if (!parents.count(node)) {
            path.pop_back();
            return;
        }
        for (const string &p : parents[node]) {
            dfs(p);
        }
        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string>& wordList) {
        beginWord = _beginWord; // store in member
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_set<string> visited, levelVisited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            levelVisited.clear();

            while (sz--) {
                string cur = q.front(); q.pop();
                string w = cur;

                for (int i = 0; i < (int)w.size(); i++) {
                    char orig = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        w[i] = c;
                        if (!dict.count(w) || visited.count(w)) continue;

                        parents[w].push_back(cur);

                        if (!levelVisited.count(w)) {
                            levelVisited.insert(w);
                            q.push(w);
                        }
                        if (w == endWord) found = true;
                    }
                    w[i] = orig;
                }
            }
            visited.insert(levelVisited.begin(), levelVisited.end());
        }

        if (!found) return {};

        dfs(endWord);
        return res;
    }
};

