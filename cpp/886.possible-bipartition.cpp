class Solution {
public:
    bool dfs(int node, vector<vector<int> > &edgeList, vector<int> &colors, int color){
	    if(colors[node] != -1) return true;
	    colors[node] = color;
	    for(auto next:edgeList[node]){
		    if(colors[next] == colors[node])return false;
		    if(!dfs(next, edgeList, colors, 1-color)) return false;
	    }
	    return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
	    vector<vector<int> > edgeList(n+1);
	    for(auto edge:dislikes){
		    edgeList[edge[0]].push_back(edge[1]);
		    edgeList[edge[1]].push_back(edge[0]);
	    }
	    vector<int> colors(n+1, -1);
	    for(int i = 1; i<=n; i++){
		    if(colors[i] != -1)continue;
		    if(!dfs(i, edgeList, colors, 0))return false;
	    }
	    return true;
    }
};
