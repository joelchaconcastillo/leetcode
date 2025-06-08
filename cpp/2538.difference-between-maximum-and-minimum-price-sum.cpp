class Solution {
public:
    void dfs2(vector<vector<int> > &adjList, vector<long long> &dp, vector<int> &price, int current, int parent, long long parent_sum, long long &res){
	 vector<pair<long long, int> > sum_child;
	 for(auto _to:adjList[current]){
		if(_to == parent)continue;
		sum_child.push_back({dp[_to], _to});
	 }
	 sort(sum_child.begin(), sum_child.end());
	 pair<long long, int> first_best(0,0), second_best(0,0);
	 if(!sum_child.empty()) first_best = sum_child.back(), sum_child.pop_back();
	 if(!sum_child.empty()) second_best = sum_child.back(), sum_child.pop_back();
	 res = max({res, parent_sum, first_best.first});
	 for(auto _to:adjList[current]){
		 if(_to == parent)continue;
		 if(_to == first_best.second) dfs2(adjList, dp, price, _to, current, price[current]+max(parent_sum, second_best.first), res);
		 else dfs2(adjList, dp, price, _to, current, price[current]+max(parent_sum, first_best.first), res);
	 }
    }
    long long dfs1(vector<vector<int> > &adjList, int current, int parent, vector<long long> &dp, vector<int> &price){
	 long long maxPath = 0;
	 for(auto _to:adjList[current]){
		if(_to == parent)continue;
		maxPath = max(maxPath, dfs1(adjList, _to, current, dp, price));
	 }
	 return dp[current] = maxPath+price[current];
    }
    long long solve(int n, vector<vector<int> > &edges, vector<int> &price){
	  vector<vector<int>> adjList(n);
	  vector<long long> dp(n,0);
	  for(auto edge:edges){
	     adjList[edge[0]].push_back(edge[1]);
	     adjList[edge[1]].push_back(edge[0]);
	  }
	  dfs1(adjList, 0, -1, dp, price);
	  long long res = 0;
	  dfs2(adjList, dp, price, 0, -1, 0, res);
	  return res;
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
	   return solve(n, edges, price);
    }
};
