class Solution {
public:
    bool solve2(vector<int> &nums){
	 int n = nums.size(), maxDist = 0;
	 if(n==1)return true;
	 for(int i = 0 ; i+1 <n ;i++){
	    maxDist = max(maxDist-1, nums[i]);
	    if(maxDist == 0)return false;
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
