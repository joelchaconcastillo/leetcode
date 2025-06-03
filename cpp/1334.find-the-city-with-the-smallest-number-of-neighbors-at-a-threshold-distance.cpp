class Solution {
public:
    int solve(int n, vector<vector<int> > &edges, int distanceThreshold){
	const int max_val = 1e5;
	vector<vector<int> > adj(n, vector<int> (n, max_val));
	for(auto edge:edges){
	   adj[edge[0]][edge[1]] = adj[edge[1]][edge[0]] = edge[2];
	}

	for(int k = 0; k < n; k++){
	   for(int i = 0 ; i < n; i++){
	      for(int j = 0 ; j < n; j++){
		  adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
	      }
	   }
	}
	pair<int, int> res(INT_MAX, 0);
	for(int i = 0 ; i < n; i++){
	   int _size = 0;
	   for(int j = 0; j < n; j++){
	      if(i==j)continue;
	      if(adj[i][j] > distanceThreshold)continue;
	      _size++;
	   }
	   res = min(res, {_size, -i});
	}

	return -res.second;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	return solve(n, edges, distanceThreshold);
    }
};
