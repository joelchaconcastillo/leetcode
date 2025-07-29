class Solution {
public:
    unordered_map<int, unordered_map<int, int >> memo;
    int helper(vector<int> &nums, int target, int i){
	    if(i==nums.size()){
		    if( target == 0)return 1;
		    return 0;
	    }
	    if(memo.count(target) && memo[target].count(i))return memo[target][i];
	    int res = 0 ;
	    res += helper(nums, target-nums[i], i+1);
	    res += helper(nums, target+nums[i], i+1);
	    return memo[target][i] = res;
    }
    int solve(vector<int> &nums, int target){
	    memo.clear();
	    return helper(nums, target, 0);
    }
    int solve2(vector<int> &nums, int target){
	    int n = nums.size();
	    unordered_map<int, int> dp;
	    dp[0] = 1;
	    for(auto num:nums){
		    auto tmp = dp;
		    tmp.clear();
		    for(auto [key, val]:dp){
			    tmp[key+num] += val;
			    tmp[key-num] += val;
		    }
		    dp=tmp;
	    }
	    return dp[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
	    return solve2(nums, target);
	    return solve(nums, target);
    }
};
