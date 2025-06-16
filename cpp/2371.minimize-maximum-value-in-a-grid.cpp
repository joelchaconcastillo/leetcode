class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > &grid){
	    int n =grid.size(), m = grid[0].size();
	    vector<tuple<int, int, int>> values_pos;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m; j++){
			   values_pos.push_back({grid[i][j], i, j});
		    }
	    }
	    sort(values_pos.begin(), values_pos.end());
	    vector<int> min_row(n, 0), min_col(m,0);
	    vector<vector<int> > res(n, vector<int>(m, 0));
	    for(auto [val, i, j]:values_pos){
		    res[i][j] = max(min_row[i], min_col[j])+1;
		    min_row[i]=max(min_row[i], res[i][j]);
		    min_col[j] = max(min_col[j], res[i][j]);
	    }
	    return res;
    }
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
