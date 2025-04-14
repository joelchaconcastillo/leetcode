class Solution {
public:
    int solve(int target, vector<int> &nums){
	int l = 0, n = nums.size(), res = INT_MAX;
	int current_sum = 0;
	for(int i = 0 ; i < n ;i++){
	   current_sum += nums[i];
	   while(current_sum >= target && l <= i){
		   res = min(res, i-l+1);
		   current_sum -= nums[l++];
	   }
	}
	if(res == INT_MAX) return 0;
	return res;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
	return solve(target, nums);
    }
};
/*
 target = 7, nums = [2,3,1,2,4,3]
2
     2  3  1  2  4  3
                 l
                    r
 * */
