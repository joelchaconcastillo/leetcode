class Solution {
public:
    int solve(vector<int> &nums){
	    nums.insert(nums.begin(), INT_MIN);
	    nums.insert(nums.begin(), INT_MAX/2);
	    sort(nums.begin(), nums.end());
	    int n = nums.size();
	    for(int i = n-2; i >=1; i--){
		    if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])return nums[i];
	    }
	    return -1;
    }
    int largestUniqueNumber(vector<int>& nums) {
       return solve(nums);
    }
};
