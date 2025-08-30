class Solution {
public:
    int gcdOfOddEvenSums(int n) {
	    int  evenSum=0, oddSum=0;
	    for(int i = 1; i<=2*n; i++){
		    if(i%2==0)evenSum+=i;
		    else oddSum+=i;
	    }
	    return __gcd(evenSum, oddSum);
    }
};
