class Solution {
public:
    int solve(vector<int> &nums){
	int n = nums.size();
	int res = 1, maxv = 1;
	for(int i = 1; i< n; i++){
	   if(nums[i]>nums[i-1]) maxv++;
	   else maxv = 1;
	   res = max(res, maxv);
	}
	return res;
    }
    int findLengthOfLCIS(vector<int>& nums) {
	return solve(nums);
    }
};
/*
  [1,3,5,4,7]  res = 3
   1 3 5 4 7
   1 


 * */
