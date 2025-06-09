class Solution {
public:

    int solve(vector<vector<int> > &height){
	vector<tuple<int, int> > directions = {
	  {0,-1}, {-1, 0}, {0,1}, {1,0}
	};
	int n = height.size(), m = height[0].size();
	vector<vector<bool> > visited(n, vector<bool> (m, false));
	typedef tuple<int, int, int> my_type;
	priority_queue<my_type, vector<my_type>, greater<>> pq;
	for(int i = 0 ; i < n ; i++){ 
	    pq.push({height[i][0], i, 0});
	    pq.push({height[i][m-1], i, m-1});
	    visited[i][0] = visited[i][m-1] = true;
	}
	for(int j = 0 ; j < m; j++){
	    pq.push({height[0][j], 0, j});
	    pq.push({height[n-1][j], n-1, j});
	    visited[0][j] = visited[n-1][j] = true;
	}
	int res = 0;
	while(!pq.empty()){
	     auto [h, r, c] = pq.top(); pq.pop();
	     for(auto [delta_r, delta_c]:directions){
		 int next_r = r+delta_r, next_c = c+delta_c;
		 if(next_r < 0 || next_r >=n || next_c < 0 || next_c>=m)continue;
		 if(visited[next_r][next_c])continue;
		 int next_height = max(h, height[next_r][next_c]);
		 res += max(0, h-height[next_r][next_c]);
		 pq.push({next_height, next_r, next_c});
		 visited[next_r][next_c]=true;
	     }
	}
	return res;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
	return solve(heightMap);
    }
};
