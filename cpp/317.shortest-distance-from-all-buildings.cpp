class Solution {
public:
    int solve(vector<vector<int> > &grid){
	int n = grid.size(), m = grid[0].size();
	vector<vector<int> > sum(n, vector<int> (m, 0));
	vector<tuple<int, int> > directions ={
	   {0,-1},{0,1}, {1,0}, {-1,0}
	};
	auto count = sum;
	for(int i = 0 ; i < n; i++){
	   for(int j = 0 ; j < m; j++){
	       if(grid[i][j] != 1) continue;
	       queue<tuple<int, int, int> > q;
	       vector<vector<bool> > visited(n, vector<bool> (m, false));
	       q.push({i,j, 0});
	       while(!q.empty()){
		     auto [row, col, dist] = q.front(); q.pop();
		     if(visited[row][col])continue;
		     visited[row][col]=true;
		     if(grid[row][col]==0){
			     count[row][col]++;
			     sum[row][col]+=dist;
		     }
		     for(auto [delta_row, delta_col]: directions){
			 int next_row = row+delta_row, next_col = col+delta_col;
			 if(next_row < 0 || next_row >=n )continue;
			 if(next_col < 0 || next_col >=m )continue;
			 if(grid[next_row][next_col] != 0) continue;
			 q.push({next_row, next_col, dist+1});
		     }
	       }
	   }
	}
	int n_build = 0;
	for(int i = 0 ; i < n ;i++){
	   for(int j = 0 ; j < m; j++){
		   n_build += grid[i][j]==1;
	   }
	}
	int res = INT_MAX;
	for(int i = 0 ; i < n; i++){
	   for(int j = 0 ; j < m ; j++){
		 if(count[i][j]!=n_build)continue;
		 res = min(res, sum[i][j]);
	   }
	}
	if(res == INT_MAX)return -1;
	return res;
    }
    int shortestDistance(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
