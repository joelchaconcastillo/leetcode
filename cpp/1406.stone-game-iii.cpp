class Solution {
public:
    int dp(vector<int> &stones, int idx, int player, vector<vector<int> > &memo){
	  if(idx == stones.size()){
	    return 0;
	  }
	  if(memo[idx][player] != -1)return memo[idx][player];
	  int sign = 1;
	  if(player == 1) sign=-1;
	  auto res = dp(stones, idx+1, 1-player, memo)+(sign)*stones[idx];
	  if(idx+1 < stones.size()){
	    auto jump1 = dp(stones, idx+2, 1-player, memo)+(sign)*(stones[idx]+stones[idx+1]);
	    if(sign*jump1 > sign*res) res = jump1;
	  }
	  if(idx+2 < stones.size()){
	    auto jump2 = dp(stones, idx+3, 1-player, memo)+(sign)*(stones[idx]+stones[idx+1]+stones[idx+2]);
	    if( sign*jump2 > sign*res) res = jump2;
	  }
	  return memo[idx][player] = res;
    }
    string solve1(vector<int> &stoneValue){
	   int n = stoneValue.size();
	   vector<vector<int> > memo(n, vector<int> (2, -1));
	   int res = dp(stoneValue, 0, 0, memo);
	   if(res > 0)return "Alice";
	   if(res < 0 )return "Bob";
	   return "Tie";
    }
    string solve2(vector<int>  &stones){
	   int n = stones.size();
	   vector<int> dp(n+1,INT_MIN);
	   dp[n] = 0;
	   for(int i = n-1; i>=0; i--){
	      int sum = 0;
	      for(int j = 0; j < 3 && i+j< n; j++){
		  sum +=stones[i+j];
		  dp[i] = max(dp[i], sum-dp[i+j+1]);
	      }
	   }
	   if(dp[0] > 0 )return "Alice";
	   if(dp[0]< 0 )return "Bob";
	   return "Tie";
    }
    string solve3(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[i][0] = Alice, dp[i][1] = Bob
    
        for (int i = n - 1; i >= 0; --i) {
            for (int player = 0; player < 2; ++player) {
                int sign = (player == 0 ? 1 : -1);
                int best = sign * -1e5;
                int sum = 0;
    
                for (int k = 0; k < 3 && i + k < n; ++k) {
                    sum += stones[i + k];
                    int val = sign * sum + dp[i + k + 1][1 - player];
                    if (sign * val > sign * best) {
                        best = val;
                    }
                }
    
                dp[i][player] = best;
            }
        }
    
        int final_score = dp[0][0]; // Starting from index 0, Alice's turn
    
        if (final_score > 0) return "Alice";
        if (final_score < 0) return "Bob";
        return "Tie";
    }

    string stoneGameIII(vector<int>& stoneValue) {
	  return solve3(stoneValue);
	  return solve2(stoneValue);
	  return solve1(stoneValue);
    }
};
