class Solution {
public:
    int solve1(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int> > dp(m+1, vector<int> (m+1,0));
	    for(int j = 0; j < m; j++){
		    for(int k=j+1; k < m; k++){
			    if( grid[0][j] == grid[0][k] && grid[0][j] == 1){
				    dp[j][k]++;
			    }
		    }
	    }
	    int res = 0;
	    for(int i = 1;i < n ; i++){
		    for(int j = 0; j < m ;j++){
			    for(int k = j+1; k < m; k++){
				    if(grid[i][j] == grid[i][k] && grid[i][j] == 1){
					    dp[j][k]++;
				    }
			    }
		    }
	    }
	    for(int j = 0; j <m; j++){
		    for(int k = j+1; k < m; k++){
			    res += (dp[j][k]*(dp[j][k]-1)/2);
		    }
	    }
	    return res;
    }
    int solve2(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size(), res=0;
	    vector<vector<int> > dp(m, vector<int> (m, 0));
	    for(int r = 0; r< n; r++){
	      for(int i = 0; i < m ; i++){
		      if(grid[r][i]==0)continue;
	              for(int j = i+1; j < m; j++){
			      if(grid[r][j]==0)continue;
			      res += dp[i][j];
			      dp[i][j]++;
	              }
	      }
	    }
	    return res;
    }
    int countCornerRectangles(vector<vector<int>>& grid) {
	    return solve2(grid);
	    return solve1(grid);
    }
};
