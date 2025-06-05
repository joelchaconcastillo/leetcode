class Solution {
public:
    int solve(vector<vector<int>>  &grid){
	int n = grid.size(), m = grid[0].size();
	vector<int> dp1 = grid[0], dp2=grid[0];
	int res = INT_MAX;
	for(int i=1; i <n; i++){
	    for(int j = 0; j  < m; j++){
		int minv = INT_MAX;
		for(int k = 0; k <m; k++){
		   if(j==k)continue;
		   minv = min(minv, dp1[k]);
		}
		dp2[j] = grid[i][j]+minv;
	    }
	    dp1 = dp2;
	}
	for(auto i:dp1)res = min(res, i);
	return res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
