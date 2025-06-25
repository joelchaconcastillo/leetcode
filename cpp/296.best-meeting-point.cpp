class Solution {
public:
    int solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<int> rows, cols;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0; j < m ; j++){
			    if(grid[i][j]==1){
				    rows.push_back(i);
				    cols.push_back(j);
			    }
		    }
	    }
	    int selected_row = rows[rows.size()/2];
	    sort(cols.begin(), cols.end());
	    int selected_col = cols[cols.size()/2];
	    int res = 0;
	    for(int i = 0; i < rows.size(); i++){
		    res += abs(selected_row-rows[i]);
	    }
	    for(int j = 0 ; j < cols.size(); j++){
		    res += abs(selected_col-cols[j]);
	    }
	    return res;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
