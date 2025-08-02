class Solution {
public:
    int solve(int n, vector<vector<int> > &edges){
	    vector<vector<tuple<int, int, int>> > adjList(n);
	    for(auto edge:edges){
		    int from = edge[0], to = edge[1];
		    int t0 = edge[2], tn = edge[3];
		    adjList[from].push_back({to, t0, tn});
	    }
	    typedef tuple<int, int> time_node_type;
	    priority_queue<time_node_type, vector<time_node_type>, greater<>> pq;
	    vector<int> min_dists(n+1, INT_MAX/2);
	    pq.push({0, 0});
	    min_dists[0] = 0;
	    while(!pq.empty()){
		    auto [_time, _node]  = pq.top(); pq.pop();
		    if(_time > min_dists[_node])continue;
		    if(_node == n-1) return min_dists[_node];
		    for(auto [to, start, end]:adjList[_node]){
			    if(_time > end)continue;
			    int next_possible_time = max(_time, start)+1;
			    if(min_dists[to] < next_possible_time)continue;
			    min_dists[to] = next_possible_time;
			    pq.push({min_dists[to], to});
		    }
	    }
	    return -1;
    }
    int minTime(int n, vector<vector<int>>& edges) {
	    return solve(n, edges);
    }
};
