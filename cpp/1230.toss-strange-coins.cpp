class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
	    int n = prob.size();
	    vector<vector<double> > dp(n+1, vector<double>(target+1, 0.0));
	    dp[0][0] = 1;
	    for(int i = 1; i <=n ;i++){
		    dp[i][0] = dp[i-1][0]*(1.0-prob[i-1]);
		    for(int k = 1; k<= target; k++){
			    dp[i][k] = dp[i-1][k-1]*prob[i-1];//changes to +1 heads
			    dp[i][k] += dp[i-1][k]*(1.0-prob[i-1]);//it is tail
		    }
	    }
	    return dp[n][target];
    }
};
