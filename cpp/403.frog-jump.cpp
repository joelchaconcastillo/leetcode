class Solution {
public:
    bool dp1(vector<int> &stones, int idx, int k, vector<vector<int> > &memo){
	if(idx+1 == stones.size()) return true;
	if(memo[idx][k]!=-1)return memo[idx][k];
	bool res = false;
	for(int i=idx+1; i < stones.size(); i++){
	   for(int k1 = max(1, k-1); k1<=k+1; k1++){
	       if(stones[i] == stones[idx]+k1)
		       res |= dp1(stones, i, k1, memo);
	   }
	}
	return memo[idx][k] = res;
    }
    int solve1(vector<int> &stones){
	vector<vector<int> > memo (stones.size(), vector<int> (stones.size(), -1));
	return dp1(stones, 0, 0, memo);
    }
	//stones = [0,1,3,5,6,8,12,17]
	//          i
	//
    int solve2(vector<int> &stones){
	int n = stones.size();
	vector<vector<bool> > dp(n+1, vector<bool> (n+1, false));//dp[i][k] = can be "i" stone be reached considering "k" len of jump
	dp[0][0]=true;//base case, first item can be reached
	for(int i = 0; i < n ;i++){ // for each stone
	   for(int k = 0; k <= n; k++){ //for each jump size
	      if(!dp[i][k])continue;//prune
	      for(int k1 = max(1,k-1); k1 <= k+1; k1++){
	         for(int j = i+1; j <n; j++){ //for each reachable stone
		    if(stones[i]+k1 != stones[j])continue;
		    dp[j][k1] = true;
		    if(j==n-1)return true;
		  }
	      }
	   }
	}

	return false;
    }
    int solve3(vector<int> &stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < n; j++) { // for each stone to reach
            for (int i = 0; i < j; i++) { // try to reach it from previous stone i
                int k = stones[j] - stones[i]; // required jump size
                if (k < 1 || k > n) continue;
                if (k - 1 >= 0 && dp[i][k - 1]) dp[j][k] = true;
                if (dp[i][k]) dp[j][k] = true;
                if (k + 1 <= n && dp[i][k + 1]) dp[j][k] = true;
                if (j == n - 1 && dp[j][k]) return true; // early exit
            }
        }
    
        return false;
    }
    bool canCross(vector<int>& stones) {
	 return solve3(stones);
	 return solve2(stones);
	 return solve1(stones);
    }
};
