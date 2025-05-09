class Solution {
public:
    int solve(int n, vector<vector<int>>&edgelist){
	const long long MOD = 1e9+7;
	unordered_map<int, vector<tuple<int, long long>>>adjList;
	vector<long long>dist(n, LLONG_MAX), ways(n, 0);
	priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<>>pq;
	for(auto edge:edgelist){
	    adjList[edge[0]].push_back({edge[1], edge[2]});
	    adjList[edge[1]].push_back({edge[0], edge[2]});
	}
	dist[0] = 0;
	ways[0] = 1;
	pq.push({0, 0});
	while(!pq.empty()){
	     auto [_dist, u] = pq.top(); pq.pop();
	     if(_dist > dist[u])continue;
	     for(auto [v, w] :  adjList[u]){
		 long long next_dist = _dist+w;
		 if(next_dist > dist[v])continue;
		 if(next_dist == dist[v]){
			 ways[v] += ways[u];
			 ways[v] %=MOD;
		 }
		 else{
		       ways[v]=ways[u];
		       dist[v] = next_dist;
		       pq.push({next_dist, v});
		 }
	     }
	}
	return ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
	return solve(n, roads);
    }
};
