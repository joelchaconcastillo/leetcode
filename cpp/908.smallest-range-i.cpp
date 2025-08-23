class Solution {
public:
    // nums = [0,10], k = 2
    //         0  10
    //
    //
    //
    // nums = [1,3,6], k = 3
    //         [-2,4]
    //         [3,9]
    //
    //
    //         1 1 1 1 1 9 9 9 9 9 9   k = 1
    //         2 2               8 8
    //
    //         1 1 1 1 1  k = 1
    //
    //
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> nums_set(nums.begin(), nums.end());	
	//the big issue would be between the largest and the smaller?
    }
};
