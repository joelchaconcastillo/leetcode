class Solution {
public:
    bool solve(vector<int> &nums){
	 int res = nums.front();
	 for(int i = 1; i < nums.size(); i++) res = __gcd(res, nums[i]);
	 return res==1;
    }
    bool isGoodArray(vector<int>& nums) {
	    return solve(nums);
    }
};
