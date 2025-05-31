class Solution {
public:
    bool isReachable(vector<vector<int> > &grid, int time){
	 vector<tuple<int, int> > directions = {
	    {0,1}, {0,-1}, {1,0}, {-1,0}
	 };
	 typedef tuple<int, int> mytype;
	 queue<mytype>q;
	 int n = grid.size(), m = grid[0].size();
	 q.push({0,0});
	 vector<vector<bool> > visited(n, vector<bool>(m, false));
	 while(!q.empty()){
	     auto [r,c] = q.front(); q.pop();
	     if(grid[r][c]>time)continue;
	     if(visited[r][c])continue;
	     visited[r][c]=true;
	     if(r==n-1 && c == m-1)return true;
	     for(auto [delta_r, delta_c]:directions){
		  int next_r = r+delta_r, next_c = c+delta_c;
		  if(next_r < 0 || next_r >=n || next_c < 0 || next_c >=m)continue;
		  if(grid[next_r][next_c] > time)continue;
		  q.push({next_r, next_c});
	     }
	 }
	 return false;
    }
    int solve1(vector<vector<int> > &grid){
	int n = grid.size(), m = grid[0].size();
	int lo = 0, hi = n*n;
	while( lo < hi){
	     int trial_time = (lo+hi)/2;
	     if(isReachable(grid, trial_time)){
		hi = trial_time;
	     }else{
	        lo = trial_time+1;	
	     }
	}
	return lo;
    }
    int solve2(vector<vector<int> > &grid){
        int n = grid.size(), m = grid[0].size();
	vector<tuple<int, int> > directions = {
          {0,-1}, {0,1}, {-1,0}, {1,0}
	};
	typedef tuple<int, int, int> mytype;
	priority_queue<mytype, vector<mytype>, greater<>> pq;
	vector<vector<int> > dist(n, vector<int> (m, INT_MAX));
	dist[0][0]=grid[0][0];
	pq.push({grid[0][0], 0, 0});
	while(!pq.empty()){
	    auto [max_t, r, c] = pq.top(); pq.pop();
	    if(r==n-1 && c==m-1)return max_t;
	    for(auto [delta_r, delta_c]:directions){
	        int next_r = r+delta_r, next_c = c + delta_c;
		if(next_r<0 || next_r>=n || next_c < 0 || next_c>=m)continue;
		int next_w = max(max_t, grid[next_r][next_c]);
		if(next_w >= dist[next_r][next_c]) continue;
		dist[next_r][next_c] = next_w;
		pq.push({next_w, next_r, next_c});
	    }
	}
	return -1;
    }
    int swimInWater(vector<vector<int>>& grid) {
	return solve2(grid);
    }
};
