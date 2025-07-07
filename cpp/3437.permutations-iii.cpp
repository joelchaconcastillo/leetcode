class Solution {
public:
    void dfs(int n, int items, vector<int> &current, vector<bool> &visited, vector<vector<int>> &res){
	    if(items==n){
		 res.push_back(current);
		 return;
	    }
	    for(int val = 1; val <= n; val++){
		    if(visited[val])continue;
		    if(!current.empty() && current.back()%2 == val%2)continue;
		    visited[val]=true;
		    current.push_back(val);
		    dfs(n, items+1, current, visited, res);
		    visited[val]=false;
		    current.pop_back();
	    }
    }
    vector<vector<int>> permute(int n) {
	    vector<vector<int> > res;
	    vector<bool> visited(n+1, false);
	    vector<int> current;
	    dfs(n, 0, current, visited, res);
	    return res;
    }
};
