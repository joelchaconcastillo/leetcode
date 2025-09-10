class Solution {
public:
    bool solve1(int c) {
	 for(long long a = 0 ; a*a <= c; a++){
	         long long b = sqrt(c-a*a);
	         if(a*a+b*b == c)return true;
	 } 
	 return false;

    }
    bool solve2(int c) {
	    long long i = 0, j = sqrt(c);
	    while( i <=j ){
		    long long sum = i*i+j*j;
		    if(sum > c)j--;
		    else if(sum<c)i++;
		    else return true;
	    }
	    return false;
    }
    bool judgeSquareSum(int c) {
	    return solve2(c);
    }
};
// a*a + b*b = c, s.t. c >= 0
// 0 <= a <= c
//
