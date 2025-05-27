class Solution {
public:
    int solve(vector<int> &nums){
	int n = nums.size();
	vector<int> dp(n,1);
	int res = 0;
	for(int i = 0 ; i < n; i++){
	   for(int j = 0 ; j < i; j++){
	       if(nums[j]>=nums[i])continue;
	       dp[i] = max(dp[j]+1, dp[i]);
	   }
	   res = max(res, dp[i]);
	}	
	return res;
    }
    int lengthOfLIS(vector<int>& nums) {
	return solve(nums);
    }
};
