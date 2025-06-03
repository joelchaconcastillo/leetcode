class Solution {
public:
    int solve(string &s, string &t){
	swap(s, t);
	int n = s.size(), m = t.size();
	// (1000)*(1000) --> 1e9
	vector<vector<unsigned long long> > dp(n+1, vector<unsigned long long> (m+1, 0));
	for(int j = 0; j <=m ;j++) dp[0][j]=1;
	for(int i = 1 ; i <=n; i++){
	   for(int j = 1; j <=m; j++){
	      if(s[i-1] != t[j-1]){
		 dp[i][j] = dp[i][j-1];
	      }else{
		 dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
	      }
	   }
	}

	return dp.back().back();
    }
    int numDistinct(string s, string t) {
	return solve(s, t);
    }
};
