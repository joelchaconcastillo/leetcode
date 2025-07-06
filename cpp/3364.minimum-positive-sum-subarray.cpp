class Solution {
public:
    int solve(vector<int> &nums, int l, int r){
	    int n = nums.size(), max_res=INT_MAX, left = 0;
	    //Input: nums = [3, -2, 1, 4], l = 2, r = 3
	    ///              i
	    ///                     j
	    for(int i = 0; i < n; i++){
		    int sum=0;
		    for(int j = i; j< n; j++){
			    sum+=nums[j];
			    if( j-i+1 < l )continue;
			    if( j-i+1 > r )break;
			    if(sum>0) max_res = min(max_res, sum);
		    }
	    }
	    if(max_res == INT_MAX)return -1;
	    return max_res;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
	    return solve(nums, l, r);
    }
};
