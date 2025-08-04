class Solution {
public:
    int solve(vector<int> &arr){
	    int n = arr.size();
	    vector<vector<int> > dp(n, vector<int> (2,0));
	    int res = 0, MOD = 1e9+7;

	    if(arr[0]%2==0)dp[0][0]=1;
	    else dp[0][1]=1;
	    res = (res+dp[0][1])%MOD;

	    for(int i = 1;i  < n ; i++){
	       if(arr[i]%2==0){
	        dp[i][0] = (1+dp[i-1][0]);
	        dp[i][1] = dp[i-1][1];
	       }else{
	        dp[i][0] = dp[i-1][1];
		dp[i][1] = dp[i-1][0]+1;
	       }
	       res = (res+dp[i][1])%MOD;
	    }
	    return res;
    }
    int solve2(vector<int> &arr){
	    int n = arr.size(), MOD=1e9+7, count=0;
	    int oddCount = 0, evenCount=1, prefixSum=0;
	    for(auto num:arr){
		    prefixSum +=num;
		    if(prefixSum % 2 == 0){
			    count += oddCount;
			    evenCount++;
		    }else{
			    count += evenCount;
			    oddCount++;
		    }
		    count %=MOD;
	    }
	    return count;
    }
    int numOfSubarrays(vector<int>& arr) {
	    return solve2(arr);
	    return solve(arr);
    }
};
/*
    even + even = even
    even + odd  = odd
    odd + odd   = even
      ans: 4 

      1   3   5

        1 0 1 0 1 0 1
        l
	i
      1   1   1 
      -  1  2  3  4  5  6  7
      0  1  3  6  10 15 21 28
         *  *        *  *
      dp[i][j] = number of subarrays ending at j with:
      i=0 --> even sum
      i=1 --> odd sum
      if a[i] % 0 == 0:
         dp[i][0] = dp[i][0]+1
	 dp[i][1] = dp[i][1]
      if a[i] % 0 == 1:
         dp[i][0] = dp[i][1]
	 dp[i][1] = dp[i][0]+1
 *
 * */
