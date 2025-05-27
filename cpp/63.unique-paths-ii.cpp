class Solution {
public:
    /*
       time: O(n*m)
       space: O(n*m)
       elapsed time to solve: 8 min.
     * */
    int solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int> > dp(n, vector<int> (m, 0));
	    for(int i = 0; i <n; i++){
		if(grid[i][0]==1)break;
		dp[i][0] = 1;
	    }
	    for(int j = 0; j <m; j++){
		if(grid[0][j]==1)break;
		dp[0][j] = 1;
	    }
	    for(int i = 1 ; i < n; i++){
	       for(int j = 1 ; j < m; j++){
		       if(grid[i][j]==1)continue;
		  dp[i][j] = dp[i-1][j]+dp[i][j-1];
	       }
	    }
	    return dp.back().back();
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	return solve(obstacleGrid);
    }
};
