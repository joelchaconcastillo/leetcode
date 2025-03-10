class Solution {
public:
    /*
       time: O(n*n)
       space: O(n*n), can be optimized to O(n)
       elapsed time to solve: >30 min.
     * */
    int solve(string &s){
	  auto t = s;
	  reverse(t.begin(), t.end());
	  int n = t.size();
	  vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
	  for(int i=1; i <= n; i++){
	     for(int j = 1; j <=n; j++){
		if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
		else{
		   dp[i][j] = max(
				   dp[i-1][j],
				   dp[i][j-1]);
		}
	     }
	  }
	  return dp.back().back();
    }
    int longestPalindromeSubseq(string s) {
	return solve(s);
    }
};
/*
  _ a a b a
_ 0 1 2 3 4
g 1 1 2 3 4
b 2 2 2 2 3
x 3 3 3 3 3
a 4 3 3 4 3
edit distance????
 dp[i][j] = min{
            dp[i-1][j]+1, //insert it
	    dp[i][j-1]+1, //remove it
	    dp[i-1][j-1]+cost(s[i], t[j])//replace it
 } 
    where
   cost(a,b) == 1 if s[i]!=t[j] 
                0 otherwise

              

   b b b a b
b  1
a    1
b      1
b        1 
b          1	
  b b b a b        a b a c a b a
  i
      j
  dp[i][j] = max {
                dp[i+1][j] + s[i+1] == s[j],
		dp[i][j-1] + s[i] == s[j],
		dp[i+1][j-1] + 2(s[i+1]==s[j-1]),
             }
   a b a a b a a
 a 1 1 3 3 4 4 4
 b   1 1 2 4 4 4
 a     1 2 2 3 3
 a       1 1 3 3
 b         1 1 2
 a           1 2
 a             1
 * */
