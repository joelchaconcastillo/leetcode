class Solution {
public:
    bool solve(int n){
	    int x = 1;
	    while(x*3<=n)x *=3;
	    while(x){
		    if(x<=n)n-=x;
		    x/=3;
	    }
	    return n==0;
    }
    bool checkPowersOfThree(int n) {
	 return solve(n);
    }
};
/*
       12 = 3^1 + 3^2

 * */
