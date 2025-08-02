class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo; 
    int target;
    int dfs(int n, int buffer){ //n = 3, 1 1 1 1 1 1 1
	    if(n>target)return 1000000;
	    if(n==target)return 0;
	    if(memo.count(n) && memo[n].count(buffer))return memo[n][buffer];
	    int res = INT_MAX;
	    res = min(res, 1+dfs(n+buffer, buffer));
	    res = min(res, 2+dfs(2*n, n));
	    return memo[n][buffer] = res;
    }
    int solve(int n){
	    if(n==1)return 0;
	    this->target = n;
	    memo.clear();
	    return 1+dfs(1, 1);
    }
    int solve2(int n){
	    vector<int> dp(n+1, 1000000);
	    dp[1]=0;
	    for(int i = 2; i <= n; i++){
		    for(int j = 1; 2*j <= i; j++){
			    if(i%j)continue;
			    dp[i] = min(dp[i], dp[j]+((i-j)/j)+1);
		    }
	    }
	    return dp[n];
    }
    int minSteps(int n) {
	    return solve2(n);
	    return solve(n);
    }
};
