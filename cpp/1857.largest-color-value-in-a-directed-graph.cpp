class Solution {
public:
    int solve(string &colors, vector<vector<int> > &edges){
	  int n = colors.size();
	  vector<vector<int> > adjList(n);
	  vector<int> inDeg(n,0);
	  for(auto edge:edges){
		 adjList[edge[0]].push_back(edge[1]);
		 inDeg[edge[1]]++;
	  }
	  queue<int> q;
	  for(int i = 0 ; i < n; i++){
		 if(inDeg[i]==0){
		    q.push(i);
	         }
	  }
	  int res = 0, processed=0;
	  vector<unordered_map<char, int>> dp(n);
	  while(!q.empty()){
		  auto node = q.front(); q.pop();
		  processed++;
		  char c = colors[node];
		  dp[node][c]++;
		  res = max(dp[node][c], res);
		  for(auto _to:adjList[node]){
			for(auto [col, count]:dp[node]){
			    dp[_to][col] = max(dp[_to][col], count);
			}
			inDeg[_to]--;
			if(inDeg[_to] == 0) q.push(_to);
		  }
	  }
	  if(processed!=n)return -1;
	  return res;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
	return solve(colors, edges);
    }
};
