class Solution {
public:
    int memo[1000000][2][2];
    int dfs(vector<int> &nums, int i, int prev, int mod){
	    if(i==nums.size())return 0;
	    if(memo[i][prev][mod] !=-1)return memo[i][prev][mod];
	    int res = dfs(nums, i+1, prev, mod);
	    if((nums[i]+prev)%2==mod)
	    res = max(res,  dfs(nums, i+1, nums[i]%2, mod)+1);
	    return memo[i][prev][mod] = res;
    }
    int solve1(vector<int>& nums) {
	    memset(memo, -1, sizeof memo);
	    int res =  dfs(nums, 0, 0, 0);
	    res = max(res, dfs(nums, 0, 1, 0));
	    res = max(res, dfs(nums, 0, 1, 1));
	    res = max(res, dfs(nums, 0, 0, 1));
	    return res;
    }
    int solve2(vector<int> &nums){
	    vector<vector<int>> dp = {{0,0},{0,0}};
	    for(auto num:nums){
		    int parity = num&1;
		    auto prev = dp;
		    for(int i = 0; i < 2; i++){
			    dp[parity][i] = prev[i][parity]+1;
		    }
	    }
	    return max({
			    dp[0][0], dp[0][1], dp[1][0],dp[1][1]
			    });
    }
    int maximumLength(vector<int>& nums) {
	    return solve2(nums);
	    return solve1(nums);
    }
};
// 1 2 3 4
// 1 0 1 0
//
//[1,2,1,1,2,1,2]
//
//      1 0 1 1 0 1 0
//      x   x x   x
//        x     x   x
//      x x   x x x x
//      dp[i][j] = max sequence until i with pair sum j
//
//      dp[next][k] = 
//      		max( dp[next][k], dp[i] + (k+nums[i])%2)
//
//       f(i, prev) =  max(
//       			f(i+1, prev),  
//       			f(i+1, prev)+1     ///iff (nums[i]+prev)%2==0
//       		  )

