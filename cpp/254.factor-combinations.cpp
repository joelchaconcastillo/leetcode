class Solution {
public:
    vector<int> factors(int n){
	  vector<int> res;
	  for(int i = 2; i < n; i++){
		  if(n%i)continue;
		  res.push_back(i);
//		  while(n%i==0) n/=i;
	  }
	  return res;
    }
    void dfs(vector<int> &factor, int idx, int n, vector<int> &current ,vector<vector<int> >&res){
	    if(idx == factor.size()){
		   if(n!=1)return;
		   if(current.empty())return;
		   res.push_back(current);
		   return;
	    }
	    if(n%factor[idx] == 0){
	       current.push_back(factor[idx]);
	       dfs(factor, idx, n/factor[idx], current, res);
	       current.pop_back();
	    }
	    dfs(factor, idx+1, n, current, res);
    }
    vector<vector<int>> solve1(int n) {
	    auto fa = factors(n);
	    vector<vector<int> > res;
	    vector<int> current;
	    dfs(fa, 0, n, current, res);
	    return res;

    }
    void bk(vector<int> &f, vector<vector<int>> &res){
	    if(f.size() > 1){
		    res.push_back(f);
	    }
	    int last = f.back(); f.pop_back();
	    int start = f.empty()?2:f.back();
	    for(int i = start ; i*i <= last; i++){
		    if(last%i!=0)continue;
		    f.push_back(i);
		    f.push_back(last/i);
		    bk(f, res);
		    f.pop_back();
		    f.pop_back();
	    }
	    f.push_back(last);
    }
    vector<vector<int>> solve2(int n) {
	    vector<vector<int> > res;
	    vector<int> f = {n};
	    bk(f, res);
	    return res;
    }
    vector<vector<int>> getFactors(int n) {
	    return solve2(n);
    }
};
