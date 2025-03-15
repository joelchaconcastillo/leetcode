class Solution {
public:
    /*
       time: O(n*n)
       space: O(n*n), can be optimized to O(n)
       elapsed time to solve: >30 min.
     * */
    int solve2(string &s){
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
    int solve(string &s){
	int n = s.size();
	vector<vector<int> > dp(n, vector<int> (n, 0));
	//base case 1: diagonal
	for(int i = 0 ; i < n ;i++) dp[i][i]=1;
	//base case 2: sup diagonal two equal characters
	for(int i = 0; i+1 < n; i++) dp[i][i+1] = s[i]==s[i+1]?2:1;
	//main transitions...
/*	for(int i = n - 2; i >=0; i--){ // n=5, 3,2,1,0 // this loop can be from bottom to top
	   for(int j = i+2; j < n; j++){ // 3,4 | 2,3,4 | 1,2,3,4 | 0,1,2,3,4
	      if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1]+2; // expand to both directions
	      else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);//max  len of either excluding i or j
	   }
	}*/
	for(int jj = 2; jj < n; jj++){ // offset of the start value
	   for(int i = 0; i+jj < n; i++){ // move on each row per offset
	      int j = i+jj; // compute the column given the offset and the row
	      if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1]+2; // expand to both directions
	      else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);//max  len of either excluding i or j
	   }
	}
	return dp[0].back();
    }
    /*
        0 1 2 3 4
     0  x x 
     1    x x 
     2      x x
     3        x x
     4          x
    
     * */
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
