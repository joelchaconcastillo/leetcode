class Solution {
public:
    int standard_robber(vector<int> nums){
	    int n = nums.size();
	    int dp1 = nums[0];
	    int dp2 = max(dp1, nums[1]);
	    for(int i = 2; i<n; i++){
		    int tmp = max(dp1+nums[i], dp2);
		    dp1 = dp2;
		    dp2=tmp;
	    }
	    return dp2;
    }
    int solve(vector<int> &nums){
	    if(nums.size() == 1)return nums.front();
	    if(nums.size()<=2){
		    return max(nums[0], nums[1]);
	    }
	    vector<int> nums1(nums.begin()+1, nums.end());
	    vector<int> nums2(nums.begin(), nums.end()-1);
	    return max(standard_robber(nums1), standard_robber(nums2));
    }
    int rob(vector<int>& nums) {
	    return solve(nums);
    }
};
/*
 
  0 1 2 3 4
  x       -
  -       x

Cases passed:  70
Total cases:   75
Last case:     [1,3,1,3,100]
                - 3 1 6 101 
Output:        101
Expected:      103

 * */
