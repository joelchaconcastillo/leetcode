class Solution {
public:
    unordered_map<int, unordered_map<int, int>>memo;
    int dfs(vector<int> &nums, int idx, int mod){
	    if(nums.size()==idx){
		    if(mod==0)return 0;
		    return INT_MIN/2;
	    }
	    if(memo.count(idx) && memo[idx].count(mod))return memo[idx][mod];
	    int res = dfs(nums, idx+1, (mod+nums[idx])%3)+nums[idx];
	    res = max(res, dfs(nums, idx+1, mod));
	    return memo[idx][mod] = res;
    }
    //dp(i,m) 
    int solve(vector<int>& nums) {
	    int n = nums.size();
	    vector<int> dp(3, INT_MIN/2);
	    dp[0]=0;
	    for(auto num:nums){
		    auto prev = dp;
		    for(int i = 0 ; i < 3; i++){
			    if(prev[i]==INT_MIN/2)continue;
			    int next = prev[i]+num;
			    dp[next%3] = max(dp[next%3], next);
		    }
	    }
	    return dp[0];
    }
    int maxSumDivThree(vector<int>& nums) {
	    return solve(nums);
	    return dfs(nums, 0, 0);
    }
};
// Input: nums = [3,6,5,1,8]
//                3
// Output: 18
