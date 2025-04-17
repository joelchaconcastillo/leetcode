class Solution {
public:
    void solve(int n, int k, vector<int> &path, vector<vector<int>> &res){
	 //prune..
	 if(n < 0) return;
	 if(path.size() > k) return ;
	 //base case
	 if(path.size() == k){
	    res.push_back(path);
	    return;
	 }
	 path.push_back(n);
	 solve(n-1, k, path, res);//taking it
	 path.pop_back();
	 solve(n-1, k, path, res);//not taking it
    }
    vector<vector<int>> combine(int n, int k) {
	 vector<int> path;
	 vector<vector<int> > result;
	 solve(n, k, path, result);
	 return result;
    }
};
