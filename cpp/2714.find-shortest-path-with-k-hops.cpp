class Solution {
public:
    int solve(int n, vector<vector<int> > &edges, int s, int d, int k){
	vector<vector<tuple<int, int>>> adjList(n);
	for(auto edge:edges){
		adjList[edge[0]].push_back({edge[1], edge[2]});
		adjList[edge[1]].push_back({edge[0], edge[2]});
	}
	const int INF = 1e8;
	typedef tuple<int, int, int> type;
	priority_queue<type, vector<type>, greater<>>pq;
	vector<vector<int> > dist(n, vector<int> (k+1, INF));
	dist[s][k] = 0;
	pq.push({0,s, k});
	int res = INF;
	while(!pq.empty()){
		auto [w, u, hop] = pq.top(); pq.pop();
		if(u == d)res=min(res, w);
		for(auto [to, to_w]:adjList[u]){
			int next_dist_1 = dist[u][hop]+to_w;
			if(next_dist_1 < dist[to][hop]){
			   dist[to][hop] = next_dist_1;
			   pq.push({next_dist_1, to, hop});
			}
			int next_dist_2 = dist[u][hop];
			if(hop>0 && next_dist_2 < dist[to][hop-1]){
			     dist[to][hop-1] = next_dist_2;
			     pq.push({next_dist_2, to, hop-1});
			 }
		}
	}
	return res;
    }
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
	    return solve(n, edges, s, d, k);
    }
};
