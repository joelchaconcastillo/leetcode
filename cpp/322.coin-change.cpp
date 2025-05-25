class Solution {
public:
//    #define INT_MAX 1000000
//     dp[i][j] = min(dp[i][j], dp[i][j-coin])
//     min num of coins taking until  i coins to obtain the amount j
//        0 1 2 3 4 5 6 7
//     1  0 1 2 3 4 5 6 7
//     2      1    
    int solve(vector<int> &coins, int amount){
	int n = coins.size();
	vector<int> dp(amount+1,INT_MAX);
	dp[0] = 0; //case base
	for(auto coin:coins){ //O(n*amount) space
	   for(int j = coin; j <= amount; j++){
	      if(dp[j-coin] == INT_MAX)continue;
	      dp[j] = min(dp[j], dp[j-coin]+1);//transition
	   }
	}
	if(dp[amount]==INT_MAX)return -1;// edge case
	return dp[amount]; // result!! 
    }
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);	    
    }
};
