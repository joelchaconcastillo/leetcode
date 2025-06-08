class Solution {
public:
    void filling_parents(int current, int parent, vector<vector<int>> &adjList, vector<int> &parents){
	  parents[current] = parent;
	  for(auto _to:adjList[current]){
	     if(_to==parent)continue;
	     filling_parents(_to, current, adjList, parents);
	  }
    }
    void dfs(vector<int> &parents, vector<vector<int> > &adjList, int sum, int &res, set<tuple<int, int>>&guesses, int k, int current, int parent){
	 if(guesses.count({parent, current})) sum--; //remove directed edge from sum
	 if(guesses.count({current, parent})) sum++; //add directed edge to sum
	 if(sum >=k) res++;
	 for(auto _to:adjList[current]){
	    if(_to == parent)continue;
	    dfs(parents, adjList, sum, res, guesses, k, _to, current);
	 }
    }
    int solve(vector<vector<int> > &edges, vector<vector<int> > &_guesses, int k){
	int n = edges.size()+1;
	vector<vector<int> > adjList(n);
	set<tuple<int, int>>guesses;
	for(auto edge:edges){
	    adjList[edge[0]].push_back(edge[1]);
	    adjList[edge[1]].push_back(edge[0]);
	}
	for(auto guess:_guesses){
	   guesses.insert({guess[0], guess[1]});
	}
	vector<int>parents(n);
	filling_parents(0, -1, adjList, parents);
	int sum=0, res = 0;
	for(int i = 1; i <n; i++) sum+= guesses.count({parents[i], i});
	if(sum >=k)res++;
	for(auto node:adjList[0]) dfs(parents, adjList, sum, res, guesses, k, node, 0);
	return res;
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
	return solve(edges, guesses, k);
    }
};
