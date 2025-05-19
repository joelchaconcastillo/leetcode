class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2){
	    int n = nums1.size(), m = nums2.size();
	    vector<vector<int > > dp(n+1, vector<int> (m+1, -1000000));
	    for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= m; j++){
		   dp[i][j] = max({
				     dp[i-1][j-1]+nums1[i-1]*nums2[j-1],
				     dp[i-1][j],
				     dp[i][j-1],
				     nums1[i-1]*nums2[j-1]
				   });
		}
	    }
	    return dp.back().back();
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
	return solve(nums1, nums2);
    }
};
/*
  nums1 = [2,1,-2,5], nums2 = [3,0,-6]
  f(n, m){

      f(n-1,m-1)+nums[n]*nums[m],
      f(n-1, m)+nums[n]*nums[m-1],
      f(n, m-1),
  }
A -> 2  1 -2 5
B -> 3 0 -6    
   f(i, j) --> max product until substring i,j 
   dp[0][j] = max(dp[0][j-1], nums1[0]*nums2[j]);
   dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0]);
   dp[i][j] = max(dp[i-1][j-1]+score, dp[i][j-1], dp[i-1][j]) 
   
    2  1  -2  5
 3  6  6  6   15
 0  6  6  6   15
-6  6  6  18  18  
   | neg | + | pos |

   a1 a2 a3
   b1 b2 
[-3,-8,3,-10,1,3,9]↩ [9,2,3,7,-9,1,-8,5,-1,-1] ans 200


(9*5)+(-8*-10)+(3*1)+(-8*-9) 
   9 2 3 7 -9 1 -8 5 -1 -1
-3       
-8         x
3             x
-10             x
1
3
9                  x


 * */
