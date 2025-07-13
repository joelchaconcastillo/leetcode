class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
	map<set<char>, int> exist;
	for(auto word:words){
		set<char> tmp(word.begin(), word.end());
		res += exist[tmp];
		exist[tmp]++;
	}
	return res;
    }
};
