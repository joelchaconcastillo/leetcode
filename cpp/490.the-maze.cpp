class Solution {
public:
    bool isValid(int row, int col, vector<vector<int> > &maze){
	    int n = maze.size(), m = maze[0].size();
	    if(row < 0 || row>=n || col<0 || col>=m)return false;
	    if(maze[row][col] == 1)return false;
	    return true;
    }
    bool solve(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination){
	    vector<tuple<int, int> > directions = {
		    {0,1}, {0,-1}, {1,0}, {-1,0}
	    };
	    queue<tuple<int, int> > q;
	    q.push({start[0], start[1]});
	    set<tuple<int, int> > visited;
	    while(!q.empty()){
		    auto [row, col] = q.front(); q.pop();
		    if(visited.count({row, col}))continue;
		    visited.insert({row, col});
		    if( row == destination[0] && col == destination[1])return true;
		    for(auto [delta_row, delta_col]:directions){
			    int current_row = row, current_col = col;
			    while( isValid(current_row+delta_row, current_col+delta_col, maze)){
				    current_row += delta_row;
				    current_col += delta_col;
			    }
			    q.push({current_row, current_col});
		    }
	    }
	    return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	    return solve(maze, start, destination);
    }
};
