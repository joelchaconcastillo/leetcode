class Solution {
public:
    int solve2(vector<int> &prices){
	int n = prices.size();
	int res = 0;
	for(int i = 1; i < n; i++){
	   res += max(0, prices[i]-prices[i-1]);
	}
	return res;
    }
    int solve(vector<int> &prices){
	int n = prices.size();
	vector<int> dp(n+1, 0);
	dp[0] = 0;
	for(int i = 1; i < n; i++){ //if we sell on day i what happens?
	   for(int j = 0; j <= i; j++){ //best buying at day j
	      dp[i+1] = max(dp[i+1], dp[j]+max(0, prices[i]-prices[j]));
	   }
	}
	return dp.back();
    }
    int solve1(vector<int> &prices){
	int n = prices.size();
	vector<vector<int>>dp(n, vector<int> (2,INT_MIN));
	dp[0][0] = -prices[0];//buy
        dp[0][1] = 0;//sell
        for(int i = 1; i <n; i++){
	   dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0]);
	   dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1]);
	}
	return max(dp[n-1][0], dp[n-1][1]);
    }
    int maxProfit(vector<int>& prices) {
	return solve1(prices);
	return solve2(prices);
    }
};
/*
  dp[i] = max(dp[i], dp[j-1]+max(0, prices[i]-prices[j]));
 * */
