class Solution {
public:
    int solve(vector<int> &nums, int k){
	    int n = nums.size(), res = 0;
	    for(int i = 0; i < n; i++){
		    for(int j = i+1; j < n; j++){
			    int attempt = nums[i]+nums[j];
			    if(attempt > res && attempt < k)
				    res = attempt;
		    }
	    }
	    if(res == 0)return -1;
	    return res;
    }
    int twoSumLessThanK(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
