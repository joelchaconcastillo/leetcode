class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> char2Pos;
	int n = s.size();
        for(int i = 0 ; i < n; i++) char2Pos[s[i]].push_back(i);
	int res = 0;
	for(auto word:words){
		int last=0, match = 0;
		for(auto letter:word){
			auto &row = char2Pos[letter];
			int idx = lower_bound(row.begin(), row.end(), last)-row.begin();
			if(idx >= row.size()) break;
			last = row[idx]+1;
			match++;
		}
		if(match==word.size())res++;
	}
	return res;
    }
};
