class Solution {
public:
    int solve(vector<vector<char> > &matrix){
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int> > dp(n+1, vector<int> (m+1, 0));

	for(int i = 1; i <= n; i++){
	   for(int j = 1; j<=m; j++){
	      dp[i][j] = 
		      dp[i][j-1]
		      +dp[i-1][j]
		      -dp[i-1][j-1]
		      +(matrix[i-1][j-1]=='1');
	   }
	}

	int res = 0;
	for(int i = 1; i<= n; i++){
	   for(int j = 1; j<=m; j++){
	       int ii=i, jj=j;
	       while(ii<=n && jj <=m){
		    int current_area = dp[ii][jj] - dp[i-1][jj] - dp[ii][j-1]+dp[i-1][j-1];
		    if(current_area != (ii-i+1)*(ii-i+1)) break;
		    res = max(res, current_area);

		    ii++,jj++;
	       }
	   }
	}
	return res;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
	return solve(matrix);
    }
};
