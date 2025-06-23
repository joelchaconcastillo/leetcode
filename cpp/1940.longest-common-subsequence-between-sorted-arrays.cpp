class Solution {
public:
    vector<int> solve(vector<vector<int>> &arrays){
	    unordered_set<int> tmp(arrays.front().begin(), arrays.front().end());
	    int n = arrays.size();
	    for(int i = 1; i < n; i++){
		    unordered_set<int> tmp2;
		    for(auto ii:arrays[i]){
			    if(tmp.count(ii))tmp2.insert(ii);
		    }
		    tmp=tmp2;
	    }
	    vector<int> res(tmp.begin(), tmp.end());
	    sort(res.begin(), res.end());
	    return res;
    }
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
	    return solve(arrays);
    }
};
