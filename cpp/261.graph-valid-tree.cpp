class Solution {
public:
    bool dfs(int current, unordered_map<int, vector<int> > &edgeList, unordered_set<int> &visited, int parent=-1){
	    if(visited.count(current))return false;
	    visited.insert(current);
	    bool res = true;
	    for(auto _to:edgeList[current]){
		    if(_to==parent)continue;
		    res &= dfs(_to, edgeList, visited, current);
	    }
	    return res;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
	    if(edges.size()+1 != n)return false;
         unordered_map<int, vector<int> > edgeList(n);
	 for(auto edge:edges){
		 edgeList[edge[0]].push_back(edge[1]);
		 edgeList[edge[1]].push_back(edge[0]);
	 }
	 unordered_set<int> visited;
	 bool check = dfs(0, edgeList, visited);
	 if(!check)return false;
	 return visited.size() == n;
    }
};
