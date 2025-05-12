class Solution {
public:
    int dfs_subtree(vector<int> &dp, vector<int> &_size, int n, int current, unordered_map<int, vector<int> >  &adjList, int parent=-1){
	int res = 1;
	for(auto _to:adjList[current]){
	    if(parent == _to) continue;
	    res +=dfs_subtree(dp, _size, n, _to, adjList, current);
	    dp[current] += dp[_to]+_size[_to];
	}
	return _size[current] = res;
    }
    void dfs(vector<int> &dp, vector<int> &_size, int n, int current, unordered_map<int, vector<int> > &adjList, int parent=-1){
	 for(auto _to:adjList[current]){
	    if(_to == parent)continue;
	    dp[_to] = dp[current] - _size[_to] + n - _size[_to];
	    dfs(dp, _size, n, _to, adjList, current);
	 }
    }
    vector<int> solve(int n, vector<vector<int>> &edges){
	  vector<int> dp(n, 0), _size(n, 0);
	  unordered_map<int, vector<int>> adjList;
	  for(auto edge:edges){
	      adjList[edge[0]].push_back(edge[1]);
	      adjList[edge[1]].push_back(edge[0]);
	  }
	  dfs_subtree(dp, _size, n, 0, adjList);
	  dfs(dp, _size, n, 0, adjList);
	  return dp;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        return solve(n, edges);	    
    }
};
