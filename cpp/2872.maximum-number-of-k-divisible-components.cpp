class Solution {
public:
    int n;
    long long transverse(unordered_map<int, vector<int>> &adjList, vector<int> &val, int k, int &res, int current=0, int parent=-1){
	if(current >= n)return 0;
	long long sum = val[current];
	for(auto _to:adjList[current]){
	    if(_to==parent)continue;
	    sum += transverse(adjList, val, k, res, _to, current);
	}
	if(sum%k==0)sum=0, res++;
	return sum;
    }
    int solve(int n, vector<vector<int> > &edges, vector<int> &values, int k){
	this->n = n;
	unordered_map<int, vector<int>> adjList(n);
	for(auto edge:edges){
	   adjList[edge[0]].push_back(edge[1]);
	   adjList[edge[1]].push_back(edge[0]);
	}
        int Ncomponents = 0;
	transverse(adjList, values, k, Ncomponents);
	return Ncomponents;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
	return solve(n, edges, values, k);
    }
};
