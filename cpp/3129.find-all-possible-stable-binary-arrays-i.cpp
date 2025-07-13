class Solution {
public:

    int Solve(int zero, int one, int limit){
	    const int MOD = 1e9+7;
	    std::vector<vector<vector<int> > > dp(zero+1, vector<vector<int> > (one+1, vector<int> (2, 0)));
	    for(int i = 1 ; i <= min(zero, limit); i++) dp[i][0][0] = 1;//taking i zeros with max size limit
	    for(int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;
	    for(int i = 0; i <= zero; i++){
		    for(int j = 0 ; j <= one; j++){
			 if( i > 0){
				 int sum = 0;
				 for(int len = 1; len <=limit && len <=i; len++){
					 sum = (sum+dp[i-len][j][1])%MOD;
				 }
				 dp[i][j][0] = (dp[i][j][0]+sum)%MOD;
			 }
			 if(j > 0){
				 int sum = 0;
				 for(int len = 1; len <=limit && len<=j; len++){
					 sum = (sum+dp[i][j-len][0])%MOD;
				 }
				 dp[i][j][1] = (dp[i][j][1]+sum)%MOD;
			 }
		    }
	    }
	    return (dp[zero][one][0] + dp[zero][one][1])%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
	    return Solve(zero, one, limit);
    }
};
