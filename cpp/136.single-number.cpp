class Solution {
public:
    int solve(vector<int> &nums){
	int res = 0;
	for(auto i:nums) res ^=i;
	return res;
    }
    int singleNumber(vector<int>& nums) {
	return solve(nums);
    }
};
