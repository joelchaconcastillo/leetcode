class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    for(int i = 0 ; i < n ; i++){
		    vector<int>row;
		    int j = 0, ii=i;
		    while(ii<n &&j<m){
			    row.push_back(-grid[ii][j]);
			    ii++;
			    j++;
		    }
		    sort(row.begin(), row.end());
		    j = 0, ii=i;
		    while(ii<n &&j<m){
			    grid[ii][j] = -row[j];
			    ii++;
			    j++;
		    }
	    }
	    for(int j = 1; j < m; j++){
		    int i = 0;
		    int jj = j;
		    vector<int> row;
		    while(i<n && jj<m){
			    row.push_back(grid[i][jj]);
			    i++; jj++;
		    }
		    sort(row.begin(), row.end());
		    i = 0, jj=j;
		    while(i<n && jj<m){
			    grid[i][jj]=row[i];
			    i++; jj++;
		    }
	    }
	    return grid;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
