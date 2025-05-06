class Solution {
public:
    void dfs(int current, unordered_map<int, vector<int>> &adjList,unordered_set<int> &visited, vector<int> skip){
	 if(visited.count(current))return;
	 visited.insert(current);
	 for(auto _to:adjList[current]){
		 vector<int> edge1 = {current, _to};
		 vector<int> edge2 = {_to, current};
		 if(skip == edge1 || skip == edge2)continue;
		 if(visited.count(_to))continue;
		 dfs(_to, adjList, visited, skip);
	 }
    } 
    vector<int> solve(vector<vector<int> >&edges){
	    unordered_map<int, vector<int> > adjList;
	    unordered_set<int>existentNodes;
	    for(auto e:edges){
		   adjList[e[0]].push_back(e[1]);
		   adjList[e[1]].push_back(e[0]);
		   existentNodes.insert(e[1]);
		   existentNodes.insert(e[0]);
	    }
	    int n = existentNodes.size();
	    for(int i = edges.size()-1; i>=0 ;i--){
		 unordered_set<int> visited;
		 dfs(*existentNodes.begin(), adjList, visited, edges[i]);
	         if(visited.size()== n)return edges[i];
	    }
	    return {};
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	 return solve(edges);
    }
};
