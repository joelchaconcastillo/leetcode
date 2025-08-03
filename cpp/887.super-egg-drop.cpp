class Solution {
public:
// dp[k][n] = maximum number of movements to solve the problem with n floors and k eggs
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs(int k, int n){
	    if(n<=1)return n;
	    if(k==1) return n;
	    if(memo.count(k) && memo[k].count(n))return memo[k][n];
	    int lo=1, hi=n;
	    while(lo+1 < hi){
		    int x_mid = (lo+hi)/2;
		    int broken_egg = dfs(k-1, x_mid-1); //f(x) increasing
		    int unbroken_egg = dfs(k, n-x_mid);//f(x) decreasing
		    if(broken_egg < unbroken_egg) lo=x_mid;
		    else if(broken_egg > unbroken_egg) hi=x_mid;
		    else lo=hi=x_mid;//equal-->critical point!
	    }
	    int worst_broken = max(dfs(k-1, lo-1), dfs(k, n-lo));
	    int worst_unbroken = max(dfs(k-1, hi-1), dfs(k, n-hi));
	    return memo[k][n] = 1+min(worst_broken, worst_unbroken);
    }
    int solve(int k, int n){
	    return dfs(k, n);
    }
    int solve2(int k, int n){
	    vector<int> dp(n+1);
	    for(int i = 0 ; i <=n; i++) dp[i]=i;
	    for(int j = 2; j<=k; ++j){///try it with less eggs, then increase them one by one
		    vector<int> dp2(n+1);
		    int x = 1;
		    for(int i = 1; i<=n ; i++){
			    while(x<i && max(dp[x-1], dp2[i-x])>max(dp[x],dp2[i-x-1]))x++;
			    dp2[i] = 1+max(dp[x-1], dp2[i-x]);
		    }
		    dp = dp2;
	    }
	    return dp[n];
    }
    int f(int x, int k, int n){
	    int res = 0, r = 1;
	    for(int i = 1; i <= k; i++){
		    r *= x-i+1;
		    r /=i;
		    res +=r;
		    if(res >=n) break;
	    }
	    return res;
    }
    //find the min-max number of floors that we can handle with k eggs
    int solve3(int k, int n){
	    int lo = 1, hi = n;
	    while(lo<hi){
		    int mid = (lo+hi)/2;
		    if(f(mid, k, n) >= n) hi = mid;// | - - - - - mid  - - - - - - |
		    else lo = mid+1;
	    }
	    return lo;
    }
    int superEggDrop(int k, int n) {
	    return solve3(k, n);
	    return solve2(k, n);
	    return solve(k, n);
    }
};
