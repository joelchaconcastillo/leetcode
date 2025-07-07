class Solution {
public:
    int solve(vector<string> &wordsDict, string &word1, string &word2){
	    unordered_map<string, vector<int> > pos;
	    int n =wordsDict.size();
	    for(int i = 0 ; i < n; i++){
		    pos[wordsDict[i]].push_back(i);
	    }
	    int res = INT_MAX;
	    for(auto idx:pos[word1]){
		    for(auto idx2:pos[word2]){
			    res = min(res, abs(idx-idx2));
		    }
	    }
	    return res;
    }
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
	    return solve(wordsDict, word1, word2);
    }
};
