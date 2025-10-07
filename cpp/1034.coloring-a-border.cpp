class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
	vector<tuple<int, int> > directions = {
		{0,1}, {0,-1}, {1,0}, {-1,0}
	};
	int n = grid.size(), m = grid[0].size();
        queue<tuple<int, int> >q;
	q.push({row, col});
	int prev_color = grid[row][col];
	set<tuple<int, int>>marked;
	while(!q.empty()){
		auto [r, c] = q.front(); q.pop();
		if(marked.count({r,c}))continue;
		marked.insert({r,c});
		for(auto [delta_r, delta_c] : directions){
			int next_r = delta_r+r, next_c = delta_c+c;
			if(next_r >=n || next_c >=m || next_r<0 || next_c<0){
				grid[r][c] = INT_MAX;
				continue;
			}
			if( grid[next_r][next_c] != prev_color &&
					grid[next_r][next_c] != INT_MAX){
				grid[r][c] = INT_MAX;
				continue;
			}
			q.push({next_r, next_c});
		}
	}
	for(int i = 0 ;i < n; i++){
		for(int j = 0 ;j < m; j++){
			if(grid[i][j] == INT_MAX)
			grid[i][j]=color;
		}
	}
	return grid;
    }
};
