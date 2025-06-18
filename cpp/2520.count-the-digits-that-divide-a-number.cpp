class Solution {
public:
    int solve(int n){
	    int res = 0;
	    int k = n;
	    while(k){
		    res += (n%(k%10)==0);
		    k/=10;
	    }
	    return res;
    }
    int countDigits(int num) {
	    return solve(num);
    }
};
