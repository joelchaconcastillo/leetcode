class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freq;
        for(auto i:s)freq[i]++;
        for(auto i:t)freq[i]--;
	int res = 0;
	for(auto [a,b]:freq) res+=abs(b);
	return res;
    }
};
