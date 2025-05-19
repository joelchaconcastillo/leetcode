class Solution {
public:
    int solve(vector<vector<int> > &grid){
	int n = grid.size(), m = grid[0].size();
	typedef tuple<int, int, int> my_type;
	priority_queue<my_type, vector<my_type>, greater<>> pq;
	vector<vector<int> > dists(n, vector<int> (m, INT_MAX));
	vector<tuple<int, int> > directions = {
	   {0,1}, {0,-1}, {1,0}, {-1,0}
	};
	dists[0][0]=0;
	pq.push({0,0,0});
	while(!pq.empty()){
	   auto [w, r, c] = pq.top(); pq.pop();
	   for(auto [nr, nc]:directions){
	       int next_r = nr+r, next_c = nc+c;
	       if(r==n-1 && c==m-1) return w;
	       if(next_r < 0 || next_r >=n)continue;
	       if(next_c < 0 || next_c >=m)continue;
	       int score = grid[next_r][next_c];
	       int next_dist = w+score;
	       if(next_dist >= dists[next_r][next_c])continue;
	       dists[next_r][next_c] = next_dist;
	       pq.push({next_dist, next_r, next_c});
	   }
	}
	return -1;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
