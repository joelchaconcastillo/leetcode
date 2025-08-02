class Solution {
public:
    void dfs(int node, vector<vector<int> > &adjList, unordered_set<int>&visited, int &nodes, int &edges){
	    if(visited.count(node))return;
	    visited.insert(node);
	    nodes++;
	    edges +=adjList[node].size();
	    for(auto to:adjList[node]){
		    dfs(to, adjList, visited, nodes, edges);
	    }
    }
    int solve(int n, vector<vector<int> >&edges){
	    vector<vector<int> > adjList(n);
	    for(auto edge:edges){
		    adjList[edge[0]].push_back(edge[1]);
		    adjList[edge[1]].push_back(edge[0]);
	    }
	    int complete_components=0;
	    unordered_set<int>visited;
	    for(int i = 0 ; i < n ; i++){
		    if(visited.count(i))continue;
		    int nodes=0, edges=0;
		    dfs(i, adjList, visited, nodes, edges);
		    edges/=2;
		    complete_components += edges == (nodes*(nodes-1)/2);
	    }
	    return complete_components;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
	    return solve(n, edges);
    }
};
