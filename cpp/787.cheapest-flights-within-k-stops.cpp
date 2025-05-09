class Solution {
public:
    int solve(int n, vector<vector<int> > &flights, int src, int dst, int k){
	typedef tuple<int, int, int> my_type;
	unordered_map<int, vector<tuple<int, int>>>adjList;
	priority_queue<my_type, vector<my_type>, greater<>> pq;
	for(auto edge:flights){
		adjList[edge[0]].push_back({edge[2], edge[1]});
	}
	vector<vector<int> > dist(n, vector<int> (n+1, INT_MAX));
	dist[src][0] = 0;
	pq.push({dist[src][0], 0, src});
	while(!pq.empty()){
	    auto [w_u, k_u, u] = pq.top(); pq.pop();
	    if(dst == u)return w_u;
	    if(k_u >k)continue;
	    for(auto [w_v, v]:adjList[u]){
		 int next_dist = w_u+w_v;
		 if(next_dist >= dist[v][k_u+1])continue;
		 dist[v][k_u+1] = next_dist;
		 pq.push({next_dist, k_u+1, v});
	    }
	}
	return -1;
    }
    //Bellman-Ford
    int solve2(int n, vector<vector<int> > &flights, int src, int dst, int k){
	  vector<int> dp(n+1, INT_MAX/2);
	  dp[src] = 0;
	  for(int i = 0 ; i <= k; i++){
	     auto dp_prev  = dp;
	     for(auto edge:flights){
		   int u = edge[0], v = edge[1], w =edge[2];
		   dp[v] = min(dp[v], dp_prev[u]+w);
	     }
	  }
	  if(dp[dst] == INT_MAX/2) return -1;
	  return dp[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return solve2(n, flights, src, dst, k);
	return solve(n, flights, src, dst, k);
    }
};
