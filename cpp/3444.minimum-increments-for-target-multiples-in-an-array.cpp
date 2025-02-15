class Solution {
public:
    long long lcm(long long a, long long b){
       return a/__gcd(a,b)*b;
    }
    long long lcm_mask(vector<int> &target, long long mask){
       long long _lcm = 1, m = target.size();
       for(int j = 0; j < m; j++){
           if( mask&(1LL<<j)){
	      _lcm = lcm(_lcm, target[j]);
           }
       }
       return _lcm;
    }
    /*
     *  time: O(N*4^M)
     *  space: O(N*2^M)  can be improved to 2^T
     * */
    int solve(vector<int> &nums, vector<int> &target){
	long long n = nums.size(), m = target.size();
	vector<vector<long long> > dp(n+1, vector<long long > ((1<<m), INT_MAX));
	long long targetMask = (1LL<<m)-1LL;
	dp[0][0]=0;
	vector<long long> lcm_values(1 << m);
        for (long long i = 0; i < (1 << m); i++) {
          lcm_values[i] = lcm_mask(target, i);
        }
	for(long long i = 1 ; i <= n; i++){
	   for(long long mask = 0; mask < (1<<m); mask++){
	       dp[i][mask] = dp[i-1][mask];
	       for (long long submask = mask; submask; submask = (submask - 1) & mask) {
		    long long lcm_val = lcm_values[submask];
                    long long rem = nums[i - 1] % lcm_val;
                    long long cost = (rem == 0) ? 0 : (lcm_val - rem);
                    if (dp[i - 1][mask ^ submask] != INT_MAX) {
                        dp[i][mask] = min(dp[i][mask], dp[i - 1][mask ^ submask] + cost);
                    }
                }
	   }
	}
	return dp[n][targetMask] == INT_MAX? -1 : dp[n][targetMask];
    }
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
	return solve(nums, target);
    }
};
/*

   dp[i][mask] --> min cost of considering item 1...i with <mask> targets

   dp[i][mask] = min(dp[i-1][mask]+cost of adding i)




   8 4      10 5 3 2
               * 
  1 <= n <= 10^4
  1 <= t <=4 !!!!
  How many operations to make t items cool?
  10, 5
     00  01  10  11
     0    5  10  10
  8  0    2   2   2  
  4  0    2   2   2
  7  0    

4,7 4 4 6

dp[i][0000] --> min(dp[j!=i][mask-bit k])
 * */
