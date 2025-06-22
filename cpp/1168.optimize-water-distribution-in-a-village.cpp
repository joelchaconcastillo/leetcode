class Solution {
public:
    int solve(int n, vector<int> &wells, vector<vector<int> > &pipes){
	    vector<vector<tuple<int, int> > > adjList(n+1);
	    for(auto edge:pipes){
		    adjList[edge[0]-1].push_back({edge[1]-1, edge[2]});
		    adjList[edge[1]-1].push_back({edge[0]-1, edge[2]});
	    }
	    for(int i = 0 ; i < wells.size(); i++){
		    adjList[n].push_back({i, wells[i]});
		    adjList[i].push_back({n, wells[i]});
	    }
	    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<> > pq;
	    int res = 0;
	    vector<bool> visited(n+1, false);
	    vector<int> min_dist(n+1,INT_MAX);
	    pq.push({0, n});
	    min_dist[n] = 0;
	    while(!pq.empty()){
		    auto [w,node] = pq.top(); pq.pop();
		    if(visited[node])continue;
		    visited[node]=true;
		    res +=w;
		    for(auto [to, cost]:adjList[node]){
			    if(visited[to])continue;
			    int next_dist = min_dist[node]+cost;
			    if(cost >= min_dist[to])continue;
			    min_dist[to]=next_dist;
			    pq.push({cost, to});
		    }
	    }
	    return res;
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
	    return solve(n, wells, pipes);
    }
};
