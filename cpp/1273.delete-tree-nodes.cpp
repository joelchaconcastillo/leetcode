class Solution {
public:
    pair<int, int> helper(int current, unordered_map<int, vector<int>> &adjList, vector<int> &value){
	    pair<int, int> res(value[current], 1);
	    for(auto next:adjList[current]){
		    auto tmp = helper(next, adjList, value);
		    res.first += tmp.first;
		    res.second += tmp.second;
	    }
	    if(res.first == 0) res.second=0;
	    return res;
    }
    int solve(int nodes, vector<int>& parent, vector<int>& value) {
	    unordered_map<int, vector<int> > adjList;
	    for(int i = 0 ; i < nodes; i++){
		    adjList[parent[i]].push_back(i);
	    }
	    return helper(0, adjList, value).second;
    }


    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
	    return solve(nodes, parent, value);
    }
};
