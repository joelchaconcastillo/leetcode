class Solution {
public:
    int solve(vector<vector<int> > &grid, int k){
	 typedef tuple<int, int, int, int> my_type;
	 queue<my_type> q;
	 int n = grid.size(), m = grid[0].size();
	 vector<tuple<int, int> > directions = {
	   {0,1}, {0,-1}, {-1,0}, {1, 0}
	 };
	 vector<vector<vector<bool>>> dist(n+2, vector<vector<bool>> (m+2, vector<bool>(n*m+2, false)));
	 q.push({0,0,0,0});
	 while(!q.empty()){
	      auto [steps, r, c, k2 ] = q.front();q.pop();
	      if(dist[r][c][k2])continue;
	      dist[r][c][k2]=true;
	      if(r==n-1 && c == m-1) return steps;
	      for(auto [delta_r, delta_c] : directions){
		 int next_r = r+delta_r, next_c = c + delta_c;
		 if(next_r < 0 || next_r >=n || next_c < 0 || next_c>=m)continue;
		 int next_k = k2;
		 if(grid[next_r][next_c] == 1) next_k++;
		 if(next_k > k )continue;
		 q.push({steps+1, next_r, next_c, next_k});
	      }
	 }
	 return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
	return solve(grid, k);
    }
};
