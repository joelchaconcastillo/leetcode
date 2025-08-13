class Solution {
public:
    int minChanges(string s) {
	    int n = s.size();
	    int res = 0;
	    for(int i=0 ; i < n; i+=2){
		    if(s[i]!=s[i+1])res++;
	    }
	    return res;
    }
    //    0  1  2  3
    //"   1  0  0  1   "
    //    1  1  1  1 --> 2
    //
    //    0  1  0  1  0  1  0  1  1
    //    0  0  1  1  
    //       1  1  0
    // dp[i] = min number of changes to make 0...i beautiful       
    // dp[i] = min( dp[i-2] + f(s[i-1:i]) )
};
