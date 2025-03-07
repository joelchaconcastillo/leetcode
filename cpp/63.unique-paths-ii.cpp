class Solution {
public:
    /*
       time: O(n*m)
       space: O(n*m)
       elapsed time to solve: 8 min.
     * */
    int solve(vector<vector<int> > &grid){
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> dp(n, vector<int> (m, 0));
	dp[0][0]=grid[0][0]==0?1:0;
	for(int i = 0 ; i < n; i++){
	   for(int j = 0 ; j < m; j++){
	       if(grid[i][j]==1)continue;
	       if(i>0)
	       dp[i][j] += grid[i-1][j]==0?dp[i-1][j]:0;
	       if(j>0)
	       dp[i][j] += grid[i][j-1]==0?dp[i][j-1]:0;
	   }
	}
	return dp[n-1][m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	return solve(obstacleGrid);
    }
};
