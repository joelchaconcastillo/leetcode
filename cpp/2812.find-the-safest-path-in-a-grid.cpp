class Solution {
public:
    vector<tuple<int, int>> directions = {
	       {-1, 0},
	   {0,-1}     , {0,1},
	       {1, 0}
    };
    int n,m;
    int solve(vector<vector<int> > &grid){
        n = grid.size(), m = grid[0].size();
	if(n==1 && m==1 && grid[0][0]==1)return 0;
	if(grid.back().back()==1)return 0;
	vector<vector<bool >> marked(n, vector<bool> (m, false));
	vector<vector<int>> safe_factors(n, vector<int> (m, INT_MAX));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> , greater<>> pq;
	for(int i = 0 ; i <n; i++){
	   for(int j = 0 ; j < m; j++){
	      if(grid[i][j]==1)pq.push({0,i,j}), safe_factors[i][j]=0;
	   }
	}
	while(!pq.empty()){
	      auto [d,r,c] = pq.top(); pq.pop();
	      if(d > safe_factors[r][c])continue;
	      for(auto [delta_r, delta_c]:directions){
		   int next_r = r+delta_r, next_c=c+delta_c;
		   if(next_r <0||next_r>=n ||next_c<0 ||next_c>=m)continue;
		   if(grid[next_r][next_c]==1)continue;
		   if(safe_factors[next_r][next_c] <= safe_factors[r][c]+1)continue;
		   safe_factors[next_r][next_c] = safe_factors[r][c]+1;
		   pq.push({ safe_factors[next_r][next_c], next_r, next_c});
	      }
	}

	priority_queue<tuple<int, int, int>> pq_path;
	vector<vector<int>> dist(n, vector<int>(m, INT_MIN));
	pq_path.push({safe_factors[0][0],0,0});
	dist[0][0]=safe_factors[0][0];
	while(!pq_path.empty()){
	      auto [d,r,c]=pq_path.top();pq_path.pop();
	      if(dist[r][c]>d)continue;
	      if(r==n-1 && c==m-1)return d; 
	      for(auto [delta_r, delta_c]:directions){
		   int next_r = r+delta_r, next_c=c+delta_c;
		   if(next_r <0||next_r>=n ||next_c<0 ||next_c>=m)continue;
		   if(grid[next_r][next_c]==1)continue;
		   if(dist[next_r][next_c] >= min(d, safe_factors[next_r][next_c])) continue;
		   dist[next_r][next_c]=min(d, safe_factors[next_r][next_c]);
		   pq_path.push({ dist[next_r][next_c], next_r, next_c});
	      }
	}
	return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
