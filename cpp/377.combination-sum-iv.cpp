class Solution {
public:
    unordered_map<int, int> memo;
    int helper(vector<int> &nums, int target){
	    if(target == 0)return 1;
	    if(target < 0) return 0;
	    if(memo.count(target))return memo[target];
	    int res = 0;
	    for(int j = 0; j < nums.size(); j++){
		    res += helper(nums, target-nums[j] );
	    }
	    return memo[target] = res;
    }
    int solve(vector<int> &nums, int target){
	    memo.clear();
	    sort(nums.begin(), nums.end());
	    return helper(nums, target);
    }
    int solve2(vector<int> &nums, long long target){
	    vector<long long> dp(target+1,0);
	    const long long MOD = 1e16+7; //instead of using MOD it can be sorted, but it might increase time-complexity
	    dp[0]=1;
	    for(long long i = 1; i<=target; i++){
		    for(auto a:nums){
			    long long num=a;
			    if(i-num>=0){
				    dp[i] = (dp[i]+dp[i-num])%MOD;
			    }
		    }
	    }
	    return static_cast<int> (dp[target]);
    }
    int combinationSum4(vector<int>& nums, int target) {
	    return solve2(nums, target);
	    return solve(nums, target);
    }
};
