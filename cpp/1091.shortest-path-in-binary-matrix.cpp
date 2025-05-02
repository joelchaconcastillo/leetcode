class Solution {
public:
    int solve(vector<vector<int>> &grid){
	if(grid.front().front()==1) return -1;
	int n = grid.size(), m = grid[0].size();
	queue<tuple<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
	q.push({0,0});
	dist[0][0] = 1;
	vector<tuple<int, int>> directions={
		{-1,-1}, {-1,0}, {-1,1},
		{0,-1}         ,{0, 1},
		{1,-1},  {1,0},  {1,1}
	};
	while(!q.empty()){
	   auto [r,c] = q.front(); q.pop();
	   for(auto [delta_r, delta_c]:directions){
		 int next_r = delta_r+r, next_c = delta_c+c;
		 if(next_r==n || next_r<0 || next_c<0||next_c==m)continue;
		 if(grid[next_r][next_c]==1)continue;
		 if(dist[next_r][next_c] <= dist[r][c]+1)continue;
		 dist[next_r][next_c] = dist[r][c]+1;
		 q.push({next_r, next_c});
	   }
	}
	if(dist.back().back()==INT_MAX)return -1;
	return dist.back().back();
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
