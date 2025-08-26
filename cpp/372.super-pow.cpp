class Solution {
public:
    long long _pow(long long a, long long b, long long mod){
	    long long res = 1;
	    while(b){
		    if(b&1)res = (res*a)%mod;
		    a = (a*a)%mod;
		    b >>=1;
	    }
	    return res;
    }
    int superPow(int a, vector<int>& b) {
	    int res = 1, n = b.size();
	    int mod = 1337;
	    for(int i = 0 ; i < n; i++){
		    res = (res*_pow(a,b[i],mod))%mod;
		    if(i+1<n)res = _pow(res, 10,mod);
	    }
	    return res;
    }
};
// a^b
// 2 , [1,0] --> ((2^1)*10)*2^0*1
// a^1234 = (a^1000)*(a^200)*(a^30)*(a^4)
//        = ((((a^1)*10)*a^2*10)*a^3*10)*a^4
//
//
//
//
//        f(a,b)=1 if b==0
//        term = f(a,b/2);
//        if( b%2==0) return term*term
//        else term*term*a;
