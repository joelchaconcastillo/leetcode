class Solution {
public:
    // find the largest even sum of a subsequence with len k
    long long solve(vector<int> &nums, int k){
	    vector<long long> even, odd;
	    for(auto num:nums){
		    if(num%2==0)even.push_back(num);
		    else odd.push_back(num);
	    }
	    sort(even.begin(), even.end());
	    sort(odd.begin(), odd.end());
	    int i = even.size()-1, j = odd.size()-1, taken=0;
	    long long sum = 0;
	    while(taken<k){
		    if(i>=0 && j>=0 && even[i] > odd[j])
			    sum+=even[i--];
		    else if(i>=0 && j>=0) sum+=odd[j--];
		    else if(i>=0) sum+=even[i--];
		    else if (j>=0)sum+=odd[j--];
		    taken++;
	    }
	    if(sum%2==1){
		    //remove last even and add an odd
		    //remove last odd and add an even
		    long long opt1 = INT_MIN, opt2=INT_MIN;
		    if(i+1 < even.size() && j>=0){
		      opt1 = sum-even[i+1]+odd[j];
		    }
		    if(j+1 < odd.size() && i >= 0){
		      opt2 = sum-odd[j+1]+even[i];
		    }
		    sum = max(opt1, opt2);
		    if(sum==INT_MIN)return -1;
	    }
	    /*
	        Last case:     [1,5,5,5,4]↩ 4
		even --> 4
		       i
		odd --> 1 5 5 5
		        j
		sum -->  19
		Output:        -1
		Expected:      16
	     * */
	    return sum;
    }
    long long largestEvenSum(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
/*
     even + even 
     odd + odd

               4 1 5 3 1  k=3

	       1 1 3 4 5   
                   i
		     j
		       k
	        3 5 7 8 10
		  * *   *
     1) take k-2 greedy
      k=1 --> 9
      k=2 --> 
      k=3 --> (6,8,4) or (5,7,8)
      k=4 --> (5,6,7,8)
      k=5 --> (4,5,6,7,8)
      1 3 5 7 9
      2 4 6 8
      if k%2==0:
         take
     nums[j]+nums[k] %2 == 0:
          find even
     else find odd

     dp[i][k][0], largest even sum on [:i] with size k
     dp[i][k][1], largest odd sum [:i] with  size k
     if nums[i]%2==0:
        dp[i][k][0] = dp[j][k-1][0]+nums[i]
	dp[i][k][1] = dp[j][k-1][0]
     else:
        dp[i][k][0] = dp[j][k-1][0]
	dp[i][k][1] = dp[j][k-1][1]+nums[i]


 * */
