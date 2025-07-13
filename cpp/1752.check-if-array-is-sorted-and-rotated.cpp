class Solution {
public:
    bool solve(vector<int> &nums){
	    int comp = 0, n = nums.size();
	    for(int i = 0; i <n ;i++){
		 comp += (nums[i] > nums[(i+1)% n]);
	    }
	    return comp <=1;
    }
    bool check(vector<int>& nums) {
	    return solve(nums);
    }
};
