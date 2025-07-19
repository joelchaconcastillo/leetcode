class Solution {
public:
    int solve(vector<int> &nums){
	 int n = nums.size(), i = n-1;
	 while(i >=0 && nums[i] == nums.back())i--;
	 int res = 0;
	 for(int j = 1 ; j <= i+1; j++){
		 if( nums[j] != nums[j-1])res++;
	 }
	 return res;
    }
    int minOperations(vector<int>& nums) {
	    return solve(nums);
    }
};
