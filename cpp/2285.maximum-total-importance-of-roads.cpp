class Solution {
public:
    long long solve(int n, vector<vector<int> > &roads){
	  vector<pair<int, int>> adj_counter(n);
	  for(auto edge:roads){
		adj_counter[edge[0]].first++;
		adj_counter[edge[0]].second = edge[0];
		adj_counter[edge[1]].first++;
		adj_counter[edge[1]].second = edge[1];
	  }
	  sort(adj_counter.begin(), adj_counter.end());
	  vector<int> weights(n,0);
	  for(int i  = 1; i <= n; i++){
	      weights[adj_counter[i-1].second] = i;
	  }
	  long long res = 0;
	  for(auto edge:roads){
	     res += weights[edge[0]]+weights[edge[1]];
	  }
	  return res;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
	 return solve(n, roads);
    }
};
