class Solution {
public:
    long long ab, bc, ac, abc;
    long long _gcd(long long a, long long b){
	    if(b==0)return a;
	    return _gcd(b, a%b);
    }
    long long _lcm(long long a, long long b){
        return a/_gcd(a,b)*b; 
    }
    long long k_ugly(long long n, long long a, long long b, long long c){
	    return n/a+n/b+n/c
		    -n/ab - n/bc-n/ac 
		    + n/abc;
    }
    //2 3 5
    // 30/1 --> 30A
    //
    // {d1,d2,d3,d4,d5,..., dk}  % (a,b,c) == 0
    // d1*a*z, d1*b*z, d1*c*z
    //

    int nthUglyNumber(int n, int a, int b, int c) {
	ab = _lcm(a,b);
	bc = _lcm(b,c);
	ac = _lcm(a,c);
	abc = _lcm(ab, c);

	long long lo=1, hi = 2e9;
	while(lo < hi){
		long long mid = lo+(hi-lo)/2;
		if( k_ugly(mid,a,b,c) >= n)
		       hi=mid;
		else lo=mid+1;
	}
	return lo;
    }
};
/// f(k) --> 
