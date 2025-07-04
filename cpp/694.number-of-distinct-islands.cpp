class Solution {
public:
    int solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid.front().size();
	    set<set<tuple<int, int> > > signatures;
	    vector<tuple<int, int> > directions = {
		    {-1,0}, {1,0}, {0,-1}, {0, 1}
	    };
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0; j < m; j++){
			 if(grid[i][j] == 0)continue;
			 queue<tuple<int, int>> q;
			 q.push({i,j});
			 set<tuple<int, int>> current_signature;
			 while(!q.empty()){
				 auto [row, col] = q.front();q.pop();
				 if(grid[row][col]==0)continue;
				 current_signature.insert({i-row, j-col});

				 grid[row][col] = 0;
				 for(auto [delta_row, delta_col]:directions){
					 int next_row = row+delta_row, next_col = col+delta_col;
					 if(next_row < 0 || next_row >=n || next_col < 0 || next_col >=m)continue;
					 if(grid[next_row][next_col] == 0)continue;
					 q.push({next_row, next_col});
				 }
			 }
			 signatures.insert(current_signature);
		    }
	    }
	    return signatures.size();
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
