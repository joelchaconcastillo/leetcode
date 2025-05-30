class Solution {
public:
    int solve(vector<int> &nums){
	int n = nums.size();
	vector<long long> dp(n, 0);
	if(n==0)return 0;
	if(n==1)return nums[0];
	if(n==2) return max(nums[0],nums[1]);
	dp[0] = nums[0];
	dp[1] = max(nums[1], nums[0]);
	for(int i = 2; i < n; i++){
	   dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
	}
	return max(dp[n-1], dp[n-2]);
    }
    int rob(vector<int>& nums) {
        return solve(nums);	    
    }
};
/*
 *
 
 [2,7,9,3,1]
  Output: 12
  dp[i] = max(dp[i], dp[i-2]-nums[i] , dp[i-1])
  	     
 * */
