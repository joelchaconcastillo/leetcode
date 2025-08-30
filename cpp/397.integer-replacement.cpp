class Solution {
public:
     unordered_map<long long, long long> memo;
    long long helper(long long n){
	if(n==1)return 0;
	if(memo.count(n))return memo[n];
	if(n%2==0) return helper(n/2LL)+1LL;
	long long res = helper(n-1)+1;
	if(n <= INT_MAX){
		res = min(res, helper(n+1)+1LL);
	}
	return memo[n] = res;
    }
    int solve1(int n){
	    return helper(n);
    }
    int solve2(int n){
	    unordered_map<long long, long long> dp;
	    dp[1]=0;
	    for(long long i = 2; i <=n; i++){
		    if(i%2==0){
		      dp[i] = dp[i/2]+1;
		    }
		    else{
		      dp[i] = min(dp[i - 1], dp[(i + 1) / 2] + 1) + 1;
		    }
	    }
	    return dp[n];
    }
    int integerReplacement(int n) {
	    return solve1(n);
	    return solve2(n);
    }
};
