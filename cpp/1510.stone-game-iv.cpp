class Solution {
public:

    bool solve(int n){
	 vector<bool> dp(n+1, false);
	 dp[1]=true;
	 for(int i = 2;i<=n ;i++){
	     for(int j = 1; j*j <= i; j++){
		 if(!dp[i-j*j]){
			 dp[i]=true;
			 break;
		 }
	     }
	 }
	 return dp.back();
    }
    bool winnerSquareGame(int n) {
	 return solve(n);
    }
};
/*
   n
   A 0 1 4 9 16 25 ... 
   B 

    0 1 2 3 4 5 6 7 8 9 10
      A B B A B A B A A B


 * */
