class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size(), current_sum=0, res = INT_MAX;
	    for(int i = 0 ; i <n; i++){
		    current_sum+=nums[i];
		    res = min(current_sum, res);
	    }
	    res = min(1, res);
	    if(res <= 0) res = -res+1;
	    return res;
    }
    int minStartValue(vector<int>& nums) {
	    return solve(nums);
    }
};
