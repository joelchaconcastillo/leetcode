class Solution {
public:
    vector<int> solve(vector<int> &nums, int target){
	   vector<int> res;
	   int n = nums.size();
	   for(int i = 0 ;i < n;i++){
		  for(int j = i+1; j < n; j++){
			  if(nums[i]+nums[j]==target){
				  return {i,j};
			  }
		  }
	   }
	   return res;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
	   return solve(nums, target);
    }
};
