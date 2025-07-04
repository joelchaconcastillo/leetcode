class Solution {
public:
    void solve(vector<vector<int> > &rooms){
	    vector<tuple<int, int> > directions = {
		    {0,-1}, {0,1}, {-1, 0}, {1, 0}
	    };
	    queue<tuple<int, int, int>>q;
	    int n = rooms.size(), m = rooms.front().size();
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0; j < m; j++){
			    if(rooms[i][j] == 0){//start from gates
				    q.push({0,i,j});
			    }
		    }
	    }
	    while(!q.empty()){
		    auto [dist, row, col] = q.front(); q.pop();
		    if(dist!=0 && rooms[row][col]!=INT_MAX)continue;
		    rooms[row][col] = dist;
		    for(auto [delta_r, delta_c] : directions){
			    int next_row = delta_r+row, next_col = delta_c+col;
			    if(next_row < 0 || next_row >= n) continue;
			    if(next_col < 0 || next_col >= m) continue;
			    if(rooms[next_row][next_col] != INT_MAX)continue;
			    q.push({dist+1, next_row, next_col});
		    }
	    }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
	    solve(rooms);
    }
};
