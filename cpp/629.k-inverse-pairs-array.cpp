class Solution {
public:
    int mod = 1e9+7;
    int memo[1001][1001];
    long long dfs(int n, int k){
	    if(k<0)return 0;
	    if(n==0)return k==0;
	    if(memo[n][k]!=-1)return memo[n][k];
	    long long res =  (dfs(n, k-1)+dfs(n-1,k));
	    if(k>=n) res -= dfs(n-1,k-n);
	    res %=mod;
	    if(res < 0) res+=mod;
	    return memo[n][k] = res;
    }
    int kInversePairs(int n, int k) {
	memset(memo, -1, sizeof memo);
        return dfs(n, k);
    }
};
// 1 2 3
//
