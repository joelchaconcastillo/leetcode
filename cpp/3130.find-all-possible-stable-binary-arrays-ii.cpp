class Solution {
public:
    int solve(int zero, int one, int limit){
	    long long MOD = 1e9+7;
	    vector<vector<vector<long long> > > dp(zero+1, vector<vector<long long> > (one+1,vector<long long> (2, 0)  ));
	    for(int i = 0; i <= min(zero,limit); i++) dp[i][0][0]=1;
	    for(int j = 0; j <= min(one, limit); j++) dp[0][j][1]=1;
	    for(int i = 1; i <= zero; i++){
		    for(int j = 1; j <= one; j++){
				   dp[i][j][0] = (dp[i-1][j][1]+dp[i-1][j][0])%MOD;
				   int deltai = i-limit-1;
				   if(deltai>=0) dp[i][j][0] = (dp[i][j][0]-dp[deltai][j][1]+MOD)%MOD;
				   dp[i][j][1] = (dp[i][j-1][0]+dp[i][j-1][1])%MOD;
				   int deltaj = j-limit-1;
				   if(deltaj>=0) dp[i][j][1] = (dp[i][j][1]-dp[i][deltaj][0]+MOD)%MOD;
		    }
	    }
	    return (dp[zero][one][0]+dp[zero][one][1])%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
	    return solve(zero, one, limit);
    }
};
