class Solution {
public:
    long long dfs(long long n, long long mask){
	    if(n==0) return 0;
	    if(__builtin_popcount(n)==1)return 1;
	    int lsb = n&(-n);
	    return min(
			    dfs(n-lsb, mask|lsb)+1,
			    dfs(n+lsb, mask|lsb)+1);
    }
    int solve(int n){
	    return dfs(n, 0);
    }
    int minOperations(int n) {
	    return solve(n);
    }
};
