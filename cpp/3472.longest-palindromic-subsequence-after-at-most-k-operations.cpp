class Solution {
public:
    int dist(char &a, char &b){
	int l = min(a, b)-'a', r=max(a, b)-'a';
	int w = 'z'-'a'+1;
	return min(r-l, w-(r-l));
    }
    /*
       time: O(n*m)
       space: O(n*m) --> can be improved to O(m) but it would need a lot of work
       elapsed time to solve it: NA
     * */
    int solve(string &s, int k){
	int n = s.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int> (k+1,0)));
	//base case 1: same character its a palindrome
	for(int i = 0 ; i < n; i++){
	   for(int l = 0; l<=k; l++){
	       	dp[i][i][l]=1;
	   }
	}
	//base case 2: first two characters are the same which is another palindrome
	for(int i = 0 ; i+1 < n; i++){
	   int cost = dist(s[i], s[i+1]);
	   for(int l = 0; l <=k ;l++){
	      dp[i][i+1][l] = (cost<=l)?2:1;
	   }
	}
	for(int l = 2; l < n; l++){ //this is the offset or len of substring //     n =5  2,3,4
           for(int i = 0; i+l < n; i++){ // 0,1,2  0,1  0
	      int j = i+l;
	      int cost = dist(s[i], s[j]); 
	      for(int kk = 0; kk <= k; kk++){
		  if(cost<=kk){
		     dp[i][j][kk] = max(
				     dp[i+1][j-1][kk-cost]+2, 
				     dp[i+1][j-1][kk]
				     );
		  }
		  dp[i][j][kk] = max({
				     dp[i][j][kk],
				     dp[i+1][j][kk],
				     dp[i][j-1][kk],
				     });
	      }
	   }
	}
	return dp[0].back().back();
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
