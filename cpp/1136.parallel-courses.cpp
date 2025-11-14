class Solution {
public:
    int solve(int n, vector<vector<int>>& relations) {
	    unordered_map<int, vector<int> > adjList;
	    unordered_map<int, int>deg;
	    for(auto &relation:relations){
		    auto from = relation[0];
		    auto to= relation[1];
		    adjList[from].push_back(to);
		    deg[to]++;
		    deg[from]+=0;
	    }
	    queue<int> q;
	    for(auto &[node, in_count]:deg){
		    if(in_count==0) q.push(node);
	    }
	    int res = 0;
	    while(!q.empty()){
		    int _sz = q.size();
		    while(_sz--){
			    auto current = q.front(); q.pop();
			    for(auto to:adjList[current]){
				    deg[to]--;
				    if(deg[to]==0){
				       q.push(to);
				    }
			    }
		    }
		    res++;
	    }
	    for(auto [node, in]:deg){
		    if(in>0)return -1;
	    }
	    return res;
    }
    bool hasCycle(int current, vector<int> &state, unordered_map<int, vector<int> > &adjList){
	 state[current] = 1;
	 for(auto next:adjList[current]){
		 if(state[next] == 1)return true;
		 if(state[next] == 0 && hasCycle(next, state, adjList))return true;
	 }
	 state[current] = 2;
	 return false;
    }
    int max_len(int current, unordered_map<int, vector<int> > &adjList){
	    int res = 0;
	    for(auto next:adjList[current]){
		    res = max(res, max_len(next, adjList));
	    }
	    return res+1;
    }
    int solve2(int n, vector<vector<int>>& relations) {
	    unordered_map<int, vector<int> > adjList;
	    for(auto &relation:relations){
		    auto from = relation[0];
		    auto to= relation[1];
		    adjList[from].push_back(to);
	    }
	    vector<int> state(n+1,0);// 0: unvisited, 1: processing, 2: visited;
	    for(int i = 1; i <= n; i++){
		    if(hasCycle(i, state, adjList))return -1;
	    }
	    int res = 0;
	    for(int i = 1; i<=n; i++){
		    res = max(res, max_len(i, adjList));
	    }
	    return res;
    }
    int minimumSemesters(int n, vector<vector<int>>& relations) {
	return solve(n, relations);
	return solve2(n, relations);
    }
};
