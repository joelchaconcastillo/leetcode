class Solution {
public:
    int solve(vector<int> &nums, int k){
	    int res = 0, sum=0;
	    for(auto num:nums) sum+=num;
	    return sum%k;
    }
    int minOperations(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
