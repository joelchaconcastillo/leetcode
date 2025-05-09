class Solution {
public:
    double solve(int n, vector<vector<int>> &edges, vector<double> &probs, int start_node, int end_node){
	    typedef tuple<double, int> my_type;
	    unordered_map<int, vector<my_type>>adjList;
	    for(int i = 0 ; i < edges.size(); i++){
		    adjList[edges[i][0]].push_back({probs[i], edges[i][1]});
		    adjList[edges[i][1]].push_back({probs[i], edges[i][0]});
	    }
	    vector<double> dist(n, 0.0);
	    priority_queue<my_type>pq;
	    dist[start_node] = 1.0;
	    pq.push({dist[start_node], start_node});
	    while(!pq.empty()){
		 auto [prob, u] = pq.top(); pq.pop();
		 if( u == end_node ) return prob;
		 if(dist[u] < prob)continue;
		 for(auto [prob_v, v]:adjList[u]){
		    double next_prob = prob*prob_v;
		    if(next_prob <= dist[v])continue;
		    dist[v] = next_prob;
		    pq.push({next_prob, v});
		 }
	    }
	    if(dist[end_node]==1.0)return 0;
	    return dist[end_node];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
	   return solve(n, edges, succProb, start_node, end_node);
    }
};
