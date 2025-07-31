class Solution {
public:
    unordered_map<int, int> memo;
    int helper(int n){
	    if(n < 0)return 0;
	    if(n == 0)return 1;
	    if(memo.count(n))return memo[n];
	    int maxres = 1;
	    for(int i = 1; i<=n; i++){
		    maxres = max(maxres, helper(n-i)*i);
	    }
	    return memo[n] = maxres;
    }
    int solve(int n){
	    memo.clear();
	    int res =1;
	    for(int i=1; i<n; i++){
	       res=max(res, i*helper(n-i));
	    }
	    return res;
    }
    int integerBreak(int n) {
	    return solve(n);
    }
};
