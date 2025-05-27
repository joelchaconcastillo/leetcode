class Solution {
public:
//Input: nums = [ 2, 3, 1, 1, 4]
//                           i
//     gas           1
//Output: true
    bool solve2(vector<int> &nums){
	 int gas = 1;
	 for(int i = 0 ; i < nums.size(); i++){
	     if(gas == 0)return false;
	     gas = max(nums[i], gas-1);
	 }
	 return true;
    }
    bool solve1(vector<int> &nums){
	 int n = nums.size();
	 vector<bool> dp(n, false);
	 dp[0] = true;
	 for(int i = 0 ; i <n ;i++){
	    if(!dp[i])continue;
	    for(int j = i; j <= min(n-1, i+nums[i]); j++){
		 dp[j]=true;
	    }
	 }
	 return dp.back();
    }
    bool canJump(vector<int>& nums) {
	 return solve2(nums);
	 return solve1(nums);
    }
};
