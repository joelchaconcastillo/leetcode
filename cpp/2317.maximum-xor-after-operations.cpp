class Solution {
public:
    int solve(vector<int> &nums){
	    int maxLeft =0;
	    for(auto num:nums){
		    maxLeft|=num;
	    }
	    return maxLeft;
    }
    int maximumXOR(vector<int>& nums) {
	    return solve(nums);
    }
};
