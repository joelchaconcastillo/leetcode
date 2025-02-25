class Solution {
public:
    bool isIncreasing(vector<int> &nums){
	int n = nums.size();
	if(n<=1)return true;
	for(int i = 0 ; i+1<n;i++){
	   if(nums[i]>nums[i+1])return false;
	}
	return true;
    }
    bool isDecreasing(vector<int> &nums){
	int n = nums.size();
	if(n<=1)return true;
	for(int i = 0 ; i+1<n;i++){
	   if(nums[i]<nums[i+1])return false;
	}
	return true;
    }
    bool solve(vector<int> &nums){
	  int n = nums.size();
	  return isIncreasing(nums) || isDecreasing(nums);
    }
    /*
     *  time: O(n)
     *  space: O(1)
     * */
    bool isMonotonic(vector<int>& nums) {
        return solve(nums);
    }
};
