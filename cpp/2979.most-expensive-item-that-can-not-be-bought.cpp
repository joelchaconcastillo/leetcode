class Solution {
public:
    int solve(int pOne, int pTwo){
	    vector<bool> dp(pOne*pTwo+1, false);
	    dp[0]=true;
	    int maxv = 0;
	    if(pOne>pTwo)swap(pOne, pTwo);
	    for(int i=pOne; i < dp.size(); i++){
		    dp[i] = dp[i-pOne];
	    }
	    for(int i=0; i< dp.size(); i++){
		    if(i-pTwo>=0)
		    dp[i] = dp[i] || dp[i-pTwo];
		    if(!dp[i]){
			    maxv=max(maxv,i);
		    }
	    }
	    return maxv;
    }
    int solve2(int a, int b){
	    return a*b-a-b;
    }
    int mostExpensiveItem(int primeOne, int primeTwo) {
	    return solve2(primeOne, primeTwo);
	    return solve(primeOne, primeTwo);
    }
};
