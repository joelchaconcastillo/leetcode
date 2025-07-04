class Solution {
public:
    bool solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid.front().size();
	    for(int i = 1; i < n; i++){
		    if(grid[i-1] != grid[i]){
			    for(int j = 0; j < m; j++){
				    grid[i][j] = 1-grid[i][j];
				    if(grid[i-1][j] != grid[i][j])return false;
			    }
		    }
	    }
	    return true;
    }
    bool removeOnes(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
