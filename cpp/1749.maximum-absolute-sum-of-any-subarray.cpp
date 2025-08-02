class Solution {
public:
    int kadane(vector<int> &nums){
	    int max_sum = nums.front(), current_sum=0;
	    for(auto num:nums){
		    current_sum = max(0, current_sum+num);
		    max_sum = max(max_sum, current_sum);
	    }
	    return max_sum;
    }
    int solve(vector<int> &nums){
	    int n = nums.size();
	    auto nums_inverted = nums;
	    for(auto &num:nums_inverted) num = -num;
	    return max(kadane(nums), kadane(nums_inverted));
    }
    int maxAbsoluteSum(vector<int>& nums) {
	return solve(nums);
    }
};
