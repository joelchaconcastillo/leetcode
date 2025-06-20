class Solution {
public:
    typedef tuple<int, int, int, int> my_type;
    int dfs(vector<int> &sweetness, int i, int k, int min_sum, int current_sum, map<my_type, int> &memo){
	    if(k<=0) return INT_MIN;
	    if(i == sweetness.size()){
		    if(k>1)return INT_MIN;
		    return min(min_sum, current_sum);
	    }
	    if(memo.count({i, k, min_sum, current_sum})) return memo[{i, k, min_sum, current_sum}];
	    int res = dfs(sweetness, i+1, k, min_sum, current_sum+sweetness[i], memo);
	    res = max(res, 
			    dfs(sweetness, i+1, k-1, min(min_sum, current_sum), sweetness[i], memo));
	    return memo[{i, k, min_sum, current_sum}] = res;
    }
    int solve(vector<int> &sweetness, int k){
	    map<my_type, int> memo;
	    return dfs(sweetness, 0, k+1, INT_MAX, 0, memo);
    }
    bool allHaveChocolate(vector<int> &sweetness, int k, int target_sum){
	    int current_sum = 0, taken=0, n = sweetness.size();
	    for(int i = 0; i < n; i++){
		    current_sum += sweetness[i];
		    if(current_sum >= target_sum){
			    taken++;
			    current_sum=0;
		    }
	    }
	    return taken >=k ;
    }
    int solve_optimized(vector<int> &sweetness, int k){
	    if(sweetness.size() < k)return 0;
	    int n = sweetness.size();
	    int lo = 1, hi = accumulate(sweetness.begin(), sweetness.end(), 0);
	    while( lo < hi){
		    int m = (lo+hi)/2;
		    if(!allHaveChocolate(sweetness, k+1, m)){
			    hi = m; // decreasing
		    }else lo=m+1; //increasing
	    }
	    if(!allHaveChocolate(sweetness, k+1, lo))return lo-1;
	    return lo;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
	    return solve_optimized(sweetness, k);
	    //return solve(sweetness, k);
    }
};
/*
 
  


 * */
