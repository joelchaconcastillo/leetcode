class Solution {
public:
    int countPrimeSetBits(int left, int right) {
	    int n = 40;
	    vector<bool> isprime(n, true);
	    isprime[0] = isprime[1]=false;
	    for(int i = 2; i < n; i++){
		    if(!isprime[i])continue;
		    for(int j = i*i; j < n; j+=i){
			    isprime[j] = false;
		    }
	    }
	    int res = 0;
	    for(int i = left; i<=right; i++){
		    if(isprime[__builtin_popcount(i)])res++;
	    }
	    return res;
    }
};
