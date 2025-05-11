class Solution {
public:
    vector<vector<int>> solve(vector<vector<int> > &mat, int k){
          int n = mat.size(), m = mat[0].size(); 
	  vector<vector<long long>> dp(n+1,vector<long long> (m+1, 0));
	  vector<vector<int> > res(n, vector<int>(m,0));
	  //precompute matrix..
	  for(int i = 1; i <= n; i++) dp[i][1] = dp[i-1][1]+mat[i-1][0];
	  for(int j = 1; j <= m; j++) dp[1][j] = dp[1][j-1]+mat[0][j-1];
	  for(int i = 1; i <= n; i++){
		for(int j = 2; j <= m; j++){
		   dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
		}
	  }

	  for(int i = 1; i <=n; i++){
	     for(int j =1; j<=m; j++){
		 int l_row = max(i-k, 1), hi_row = min(i+k, n);
		 int l_col = max(j-k, 1), hi_col = min(j+k, m);
		 res[i-1][j-1] = dp[hi_row][hi_col]-dp[l_row-1][hi_col]-dp[hi_row][l_col-1]+dp[l_row-1][l_col-1];
	     }
	  }
	  return res;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      return solve(mat, k);
    }
};
