class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
	    int n = nums.size();
	    long long dp3 = max(0, k-nums[0]);
	    long long dp2 = max(0, k-nums[1]);
	    long long dp1 = max(0, k-nums[2]);
	    for(int i = 3; i < n; i++){
		    long long tmp = min({dp1, dp2, dp3})+max(0, k-nums[i]);
		    dp3=dp2;
		    dp2=dp1;
		    dp1=tmp;
	    }
	    return min({dp1, dp2, dp3});
    }
};
// Input: nums = [2,3,0,0,2], k = 4
//                2 1 4 4 2
//                2 1 1 1 2
//                0 1 1 1 1
//                - p - - x - - -   dp[i-3] + score
//                - - p - x - - -  dp[i-2]
//                - - - - - x - -  dp[i-2]
//                - - - p x - - -  dp[i-1]
// Output: 3
//
//    k = 4
//    2  3  0  0  2
//
/*
   

   Last case:     [43,31,14,4 ]↩ 73
                   30 42 61 69
		   30 42 61 
   dp[i] = total score to make window >=73
   dp[i] = min(
                 {
		   dp[i-1] 
		   dp[i-2]
		   dp[i-3]
		 }
	      )+max(0, k-nums[i])
   Output:        72
   Expected:      42

 * */
