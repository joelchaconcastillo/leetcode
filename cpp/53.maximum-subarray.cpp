class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	int res = INT_MIN, current_sum = 0;
	for(auto i:nums){
	   current_sum += i;
	   res = max(res, current_sum);
	   current_sum = max(current_sum, 0);
	}
	return res;
    }
};
/*
      -2 1 -3 4 -1 2 1 -5 4
 * */
