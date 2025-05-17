class Solution {
public:
    int solve(vector<vector<int> > &heights){
	int n = heights.size(), m = heights[0].size();
	vector<tuple<int, int> > directions = {
		{0, -1}, {0, 1}, {-1, 0}, {1, 0}
	};
	typedef tuple<int, int, int> my_type;
	priority_queue<my_type, vector<my_type>, greater<>> pq;
	vector<vector<int> > dist(n, vector<int> (m, INT_MAX));
	pq.push({0,0,0});
	while(!pq.empty()){
	   auto [w, r, c] = pq.top(); pq.pop();
	   if(r==n-1 && c == m-1) return w;
	   for(auto [delta_r, delta_c]: directions){
		int next_r = delta_r+r, next_c = delta_c+c;
		if( next_r < 0 || next_r >= n)continue;
		if( next_c < 0 || next_c >= m)continue;
		int next_dist = max(w,abs(heights[r][c]-heights[next_r][next_c]));
		if( next_dist >= dist[next_r][next_c]) continue;
		dist[next_r][next_c] = next_dist;
		pq.push({next_dist, next_r, next_c});
	   }
	}
	return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
	    return solve(heights);
    }
};
