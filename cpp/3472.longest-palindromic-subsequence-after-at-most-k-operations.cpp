class Solution {
public:
    char _next(char &i){
        char res = i+1;
	if(res>'z')res='a';
	return res;
    }
    char _prev(char &i){
        char res = i-1;
	if(res<'a')res='z';
	return res;
    }
    int solve(string &s, int k){
    }
    int longestPalindromicSubsequence(string s, int k) {
	return solve(s, k);
    }
};
/*

   dp(i, k) = 
             max
	          {
	            dp(i+1, k-1) + f(s[i]>>1)
		    dp(i+1, k-1) + f(s[i]<<1)
		    dp(i+1, k) + f(s[i])
		    dp(i+1, k)
		  }
		where f(.) is the max palin.
   max palin subsequence....
     a b c b c
     l
             r   
   time: O(2^n)
   space: O(n)
   with memo:
   time: O(n*n)
   space: O(2^n)
   f(i, s) = max {
                  f(i+1, s),
		  f(i+1, s+t[i])
   }

   a b c e d  k = 2

   replace s[1] --> a c c e d
   replace s[4] --> a c c e c


   a c c e c
     l     
         r
   max subsequence --> c c c
   hints --> dp[i][j][k] is the length of the longest palindromic subsequence in substring [i..j] with cost at most k.

  dp[i][j][k] = max {
                        dp[i-1][j][k] + adding s[i-1],
			dp[i][j+1][k] + adding s[j+1],
			dp[i-1][j+1][k] + adding s[i-1...j+1]
                } 




 * */
