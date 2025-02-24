class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       vector<long long>dp(n, 0);
       for(int i = 1 ; i < n; i++){
	  for(int j = 0; j <= i; j++){
	     dp[i] = max(dp[i], dp[max(0, j-1)]+prices[i]-prices[j]);
	  }
       }
       return dp.back();
    }
};
/*  
     1  2  3  4  5 
        j
           i
dp   0  0  0  0  0

  prices = 
     M  
     *
  7  1  5  3  6  4
     B  S
           B  S
DP(i) --> max earns selling at day i
DP(i) = max(DP(i), DP(j-1) + cost(i)-DP(j)
O(n*n)
 * */
