class Solution {
public:
    int memo[31][31][31];
    int K;
    vector<int> prefix;
    // min score to merge stones [1,j) into k piles
    int dfs(vector<int> &stones, int i, int j, int m){
	    //base cases
	    if(j-i < m) return INT_MAX/2;
	    if(j-i == 1)return (m==1)?0:INT_MAX/2;
	    if(memo[i][j][m]!=-1)return memo[i][j][m];
	    if(m == 1){
		    int cost = dfs(stones, i,j, K);
		    if(cost >= INT_MAX/2) return memo[i][j][m] = INT_MAX/2;
		    return memo[i][j][m] = prefix[j]-prefix[i]+cost;
	    }
	    int res = INT_MAX/2;
	    for(int l = i+1; l < j; l++){
		    res = min(res,
				    dfs(stones, i,l,m-1)+
				    dfs(stones, l,j,1)
				    );
	    }
	    return memo[i][j][m] = res;
    }
    int solve1(vector<int>& stones, int k) {
	    int n = stones.size();
	    K=k;
	    if((n-1) % (k-1) != 0) return -1;
	    prefix.assign(n+1, 0);
	    for(int i = 1; i <=n; i++) prefix[i] = prefix[i-1]+stones[i-1];
	    memset(memo, -1, sizeof memo);
	    auto res = dfs(stones, 0, n, 1);
	    if(res == INT_MAX/2)return -1;
	    return res;
    }
    int solve2(vector<int> &stones, int k){
	    int n = stones.size();
	    // n - (k-1)x = 1
	    // solve for x
	    // x = (n-1)/(k-1) therefore k-1 must be a divisor of n-1
	    if( (n-1) % (k-1)!=0)return -1;
	    vector<int> prefix(n+1,0);
	    for(int i = 1; i <=n ;i++) prefix[i] = prefix[i-1]+stones[i-1];
	    vector<vector<int> > dp(n, vector<int> (n,0));
	    for(int m = k; m <=n; m++){
		    for(int i = 0; i+m <=n; i++){
			    int j = i+m-1;
			    dp[i][j] = INT_MAX;
			    for(int mid = i; mid < j; mid+=k-1){
				    dp[i][j] = min(
						    dp[i][j], 
						    dp[i][mid]+dp[mid+1][j]);
			    }
				    if((j-i)%(k-1)==0){
					    dp[i][j] += prefix[j+1]-prefix[i];
				    }
		    }
	    }
	    return dp[0][n-1];
    }
    int mergeStones(vector<int>& stones, int k) {
	    return solve2(stones, k);
    }
};
