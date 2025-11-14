class Solution {
public:
    vector<int> solve(vector<int>& pid, vector<int>& ppid, int kill) {
	    unordered_map<int, vector<int> > adjList;
	    int n = pid.size();
	    for(int i = 0 ;i < n; i++){
		    auto u = ppid[i], v = pid[i];
		    adjList[u].push_back(v);
	    }
	    queue<int> q;
	    q.push(kill);
	    unordered_set<int> visited;
	    vector<int> res;
	    visited.insert(kill);//if we know that nodes in memory are optimal then we can mark them as soon as they are on memory
	    while(!q.empty()){
		    auto current = q.front(); q.pop();
		    res.push_back(current);
		    for(auto next:adjList[current]){
			    if(visited.count(next))continue;
			    visited.insert(next);
			    q.push(next);
		    }
	    }
	    return res;
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	  return solve(pid, ppid, kill);
    }
};
