class Solution {
public:
    int solve(vector<vector<int> > &times, int n, int k){
	vector<long long> dist(n+1, INT_MAX);
	unordered_map<int, vector<tuple<int, long long>>>adjlist;
	for(auto edge:times){
		adjlist[edge[0]].push_back({edge[1], edge[2]});
	}
	priority_queue<
		   tuple<long long, int>, 
		   vector<tuple<long long, int>>, greater<> >pq;
	dist[k] = 0;
	pq.push({dist[k], k});
	while(!pq.empty()){
	     auto [wu, u] = pq.top(); pq.pop();
	     if(wu > dist[u])continue;
	     for(auto [v, w]:adjlist[u]){
		long long next_dist = dist[u]+w;
		if(next_dist >= dist[v])continue;
		dist[v] = next_dist;
		pq.push({next_dist, v});
	     }
	}
	long long res = INT_MIN;
	for(int i = 1 ; i <= n; i++){
	   res = max(res, dist[i]);
	   if(dist[i]==INT_MAX)return -1;
	}
	return res;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	return solve(times, n, k);
    }
};
