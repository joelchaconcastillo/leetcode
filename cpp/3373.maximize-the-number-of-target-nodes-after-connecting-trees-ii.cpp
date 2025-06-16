class Solution {
public:
    void dfs(vector<vector<int> > &adjList, int node, vector<int> &colors_count, int step=0, int parent=-1){
	  colors_count[step%2]++;
	  for(auto _to:adjList[node]){
		  if(parent == _to)continue;
		  dfs(adjList, _to, colors_count, step+1, node);
	  }
    }
    vector<int> solve(vector<vector<int> > &edges1, vector<vector<int> > &edges2){
	    vector<vector<int> > adjList1(edges1.size()+1);
	    vector<vector<int> > adjList2(edges2.size()+1);
	    for(auto edge:edges1){
		    adjList1[edge[0]].push_back(edge[1]);
		    adjList1[edge[1]].push_back(edge[0]);
	    }
	    for(auto edge:edges2){
		    adjList2[edge[0]].push_back(edge[1]);
		    adjList2[edge[1]].push_back(edge[0]);
	    }
	    vector<int> colors1(2,0), colors2(2, 0);
	    dfs(adjList1, 0, colors1);
	    dfs(adjList2, 0, colors2);
	    vector<int> res(edges1.size()+1);
	    vector<bool> visited(edges1.size()+1, false);
	    queue<int> q;
	    q.push(0);
	    int color=0;
	    while(!q.empty()){
		    queue<int> tmp;
		    while(!q.empty()){
			    auto node = q.front(); q.pop();
			    if(visited[node])continue;
			    visited[node]=true;
			    res[node] = colors1[color]+max(colors2[0], colors2[1]);
			    for(auto _to:adjList1[node]){
				    tmp.push(_to);
			    }
		    }
		    color=(color+1)%2;
		    q = tmp;
	    }

	    return res;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
	    return solve(edges1, edges2);
    }
};
