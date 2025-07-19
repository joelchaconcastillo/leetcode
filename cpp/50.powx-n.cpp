class Solution {
public:
	//x=2.0, n = 10
	// 1  0  1  0
	// 16 8  4  2
	// *     *
    double solve(double x, int n){
	    double product = 1.0;
	    if(n<0) x=1.0/x;
	    while(n){
		    if(n&1) product *=x;
		    x *=x;
		    n/=2;
	    }
	    return product;
    }
    double myPow(double x, int n) {
	    return solve(x, n);
    }
};
