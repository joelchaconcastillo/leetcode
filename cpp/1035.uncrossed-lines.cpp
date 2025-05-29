class Solution {
public:
    int solve3(vector<int> &nums1, vector<int> &nums2){
	int n = nums1.size(), m = nums2.size();
	vector<vector<int> > dp(2, vector<int> (m+1,0));
        for(int ii = 1; ii <=n; ii++){
          for(int j = 1; j <= m; j++){
	     int i1 = ii%2, i2 = (ii+1)%2;
	  dp[i1][j] = max({dp[i1][j-1], dp[i2][j], dp[i2][j-1]+(nums1[ii-1]==nums2[j-1])});
          }
        }
   return dp[n%2].back();

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	return solve(nums1, nums2);
    }
};
