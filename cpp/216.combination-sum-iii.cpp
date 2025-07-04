class Solution {
public:
    vector<vector<int> > res;
    int n;
    void dfs(int k, int sum, int i, vector<int> &path){
	    if(k < 0) return;
	    if(sum > n) return;
	    if( i > 9){
	        if(k==0 && sum == n) res.push_back(path);
		return;
	    }
	    dfs(k, sum, i+1, path);
	    path.push_back(i);
	    dfs(k-1, sum+i, i+1, path);
	    path.pop_back();
    }
    vector<vector<int> >solve(int k, int n){
	    res.clear();
	    this->n = n;
	    vector<int> path;
	    dfs(k, 0, 1, path);
	    return res;
    }
    vector<vector<int> > solve2(int k, int n){
	    return {};
    }
    vector<vector<int>> combinationSum3(int k, int n) {
	    return solve(k, n);
	    return solve2(k, n);
    }
};
