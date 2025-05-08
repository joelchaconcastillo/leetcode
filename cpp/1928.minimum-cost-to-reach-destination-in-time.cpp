class Solution {
public:
    int solve(int maxTime, vector<vector<int> > &edges, vector<int> &passingFees){
	    unordered_map<int, vector<tuple<int, long long>>> edge_list;
	    int n = passingFees.size();
	    for(auto e:edges){
		edge_list[e[0]].push_back({e[1],e[2]});
		edge_list[e[1]].push_back({e[0],e[2]});
	    }
	    priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<> > pq; //cost, current_time, node
	    vector<vector<long long>> dist(n, vector<long long> (maxTime+1,INT_MAX));
	    dist[0][0] = passingFees[0];
	    pq.push({dist[0][0], 0, 0});

	    while(!pq.empty()){
		  auto [current_dist, current_time, u] = pq.top(); pq.pop();
		  if(u==n-1)return current_dist;
		  if(current_time > maxTime)continue;
		  if(current_dist > dist[u][current_time])continue;
		  for(auto [v, time]:edge_list[u]){
		       long long new_dist = dist[u][current_time]+passingFees[v];
		       long long next_time = current_time+time;
		       if(next_time > maxTime)continue;
		       if(dist[v][next_time] <= new_dist) continue;
		       dist[v][next_time] = new_dist;
		       pq.push({new_dist, next_time, v});
		  }
	    }
	    return -1;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
	 return solve(maxTime, edges, passingFees);
    }
};
