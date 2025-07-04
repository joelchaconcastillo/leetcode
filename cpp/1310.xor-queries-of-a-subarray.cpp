class Solution {
public:
    vector<int> solve(vector<int> &arr, vector<vector<int> > &queries){
	    int n = arr.size();
	    vector<int> dp(n+1, 0);
	    for(int i = 1; i <= n; i++){
		    dp[i] = dp[i-1]^arr[i-1];
	    }
	    vector<int> res;
	    for(auto query:queries){
		    int left = query[0]+1, right = query[1]+1;
		    res.push_back(dp[right]^dp[left-1]);
	    }
	    return res;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	    return solve(arr, queries);
    }
};
