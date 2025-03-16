class Solution {
public:
    /*
         time: O(log a/b) -- > log(dividend/divisor)
         space: O(1)
     * */
    int solve(long long a, long long b){
	long long sign1 = a < 0LL? -1LL:1LL;
	long long sign2 = b < 0LL? -1LL:1LL;
	a = llabs(a), b = llabs(b);//a=10, b=3
	//  a ~  b*k
	//       b + (b+b) + (b+b+b+b) + (b+....+b)
	//       b + 2*b   + 4*b       + 8*b --> 2*k*b
	// 10 3 --> 3 + (3+3)
	// 7 3    1 1 1 --->  3  3+3 
	//                    0   1
	//find max value that is sum-binary pow
	long long max_b = b, res = 0, k=1;
	while( max_b < a) max_b +=max_b, k+=k;//b b+b ....
	while(max_b>=1){
	   while(a>=max_b){
	      a-=max_b;
	      res+=k;
	   }
	   max_b>>=1LL;
	   k >>=1LL;
	}
	res = sign1*sign2*res; //the only product, I had to add since I started getting json error submitting from terminal to LC, anyway I can do if statemets to resolve this!!
	if(res > INT_MAX)return INT_MAX;
	if(res < INT_MIN) return INT_MIN;
	return res;
    }
    int divide(int dividend, int divisor) {
       return (int)solve(dividend, divisor); 
    }
};
/*
   ------divisor*(2^k)---
   3 ---> 3*2^0   1
   3+3 --> 3*2^1  2
   (3+3)+(3+3) --> 3*2^2   4
   2^0 + 2^1 + 2^2 + 2^3 + 2^4 ....

   (3+3)+3

   dividend = 10, divisor =  3 --> 10/3 ~ 3
   dividend = 7 , divisor = -3 --> 7/-3 ~ -2 
   not /, *, %
   +, -
   3+3+3 --> 10
   ()
 * */
