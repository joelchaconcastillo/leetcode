class Solution {
public:
    int solve(vector<int> &nums){
	    long long lo = 0, counter = 0, n = nums.size(), res = 0, MOD = 1e9+7;
	    for(int i = 0 ; i < n; i++){
		    if(nums[i] == 1){
		      if(counter == 0)counter =1;
		      else counter = (counter*(i-lo+1))%MOD;
		      lo=i+1;
		    }
	    }
	    return counter;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
	    return solve(nums);
    }
};
