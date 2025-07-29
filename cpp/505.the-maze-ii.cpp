class Solution {
public:
    bool feasible(int row, int col, vector<vector<int> > &maze){
	    int n = maze.size(), m = maze[0].size();
	    if(row<0 || row>=n || col<0 || col>=m) return false;
	    if(maze[row][col]==1)return false;
	    return true;
    }
    int solve(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination){
	    int n = maze.size(), m = maze[0].size();
	    vector<tuple<int, int> > direction = {
		    {-1,0}, {1,0}, {0,-1}, {0,1}
	    };
	    queue<tuple<int, int, int> > q;
	    vector<vector<int> > dist(n, vector<int> (m, INT_MAX));
	    q.push({start[0], start[1], 0});
	    dist[start[0]][start[1]]=0;
	    while(!q.empty()){
		    auto [row, col, d] = q.front(); q.pop();
		    if(d > dist[row][col])continue;
		    for(auto [delta_row, delta_col] : direction){
			    int current_row = row, current_col = col;
			    int moves = 0;
			    while( feasible(current_row+delta_row, current_col+delta_col, maze)){
				    current_row += delta_row;
				    current_col += delta_col;
				    moves++;
			    }
			    if( dist[row][col] + moves >= dist[current_row][current_col])continue;
			    dist[current_row][current_col] = dist[row][col]+moves;
			    q.push({current_row, current_col, dist[current_row][current_col]});
		    }
	    }
	    auto val = dist[destination[0]][destination[1]];
	    if(val == INT_MAX)return -1;
	    return val;
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	    return solve(maze, start, destination);
    }
};
