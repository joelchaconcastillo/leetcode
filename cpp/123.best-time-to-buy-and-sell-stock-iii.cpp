class Solution {
public:
    int solve2(vector<int> &prices){
	int n = prices.size();
	int hold1=INT_MIN, release1=0;// keep current stock, sell it
	int hold2=INT_MIN, release2=0;
	for(auto price:prices){
	   release2 = max(release2, hold2+price); // sell stock2
	   release1 = max(release1, hold1+price); // sell stock1
	   hold2 = max(hold2, release1-price); // sell stock1 and buy price
	   hold1 = max(hold1, -price); //buy price
	}
	return release2;
    }
    int solve(vector<int> &prices){
	int n = prices.size();
	int k = 2;
	vector<int> dp(n,0);
	int minv = prices[0];
	for(int i = 1 ; i<n; i++){
	   dp[i] = max(dp[i-1], max(prices[i]-minv,0));
	   minv = min(minv, prices[i]);
	}
	int maxv = prices.back(), res=0, maxp=0;
	for(int i = n-1; i>=0; i--){
	   res = max(res, dp[i]+maxp);
	   maxp = max(maxp, maxv-prices[i]);
	   maxv = max(maxv, prices[i]);
	}
	return res;
    }
    int maxProfit(vector<int>& prices) {
	return solve2(prices);
	return solve(prices);
    }
};
