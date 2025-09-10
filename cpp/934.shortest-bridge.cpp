class Solution {
public:
    vector<tuple<int, int> > directions = {
	    {-1,0}, {1,0}, {0,-1}, {0,1}
    };
    void enumerate_islands(vector<vector<int>>& grid) {
	    int n = grid.size(), m = grid[0].size();
	    int island_counter = 2;
	    for(int i = 0 ;i < n ;i ++){
		    for(int j = 0 ;j < m ; j++){
			    if(grid[i][j] != 1) continue;
			    queue<tuple<int, int> > q;
			    q.push({i, j});
			    while(!q.empty()){
				    auto [row, col] = q.front(); q.pop();
				    if(grid[row][col]!=1)continue;
				    grid[row][col] = island_counter;
				    for(auto [delta_row, delta_col]: directions){
					    int next_row = row+delta_row, next_col = col+delta_col;
					    if( next_row < 0 || next_row >=n ) continue;
					    if( next_col < 0 || next_col >=m ) continue;
					    if(grid[next_row][next_col] !=1)continue;
					    q.push({next_row, next_col});
				    }

			    }
			    island_counter++;
		    }
	    }
    }
    int shortestBridge(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();
        enumerate_islands(grid);	    
	queue<tuple<int, int>> q;//zeros, row, col
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ;j  < m ;j++){
			if(grid[i][j] == 2)q.push({i,j});
		}
	}
	int level = 0;
	while(!q.empty()){
		int _sz = q.size();
		while(_sz--){
		    auto [i,j] = q.front(); q.pop();
		    for(auto [delta_row, delta_col]:directions){
		    	int next_row = i+delta_row, next_col = j+delta_col;
		    	if(next_row < 0|| next_row>=n || next_col<0 || next_col>=m)continue;
		    	if(grid[next_row][next_col]==3) return level;
			if(grid[next_row][next_col]!=0)continue;
			grid[next_row][next_col] = 2;
			q.push({next_row, next_col});
		    }
		}
		level++;
	}
	return 0;
    }
};
