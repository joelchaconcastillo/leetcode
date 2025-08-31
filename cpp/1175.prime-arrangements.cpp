class Solution {
public:
    vector<bool> isPrime;
    int computePrimes(int n){
	    isPrime.assign(n+1, true);
	    isPrime[0] = isPrime[1]=false;
	    int cont = 0;
	    for(long long i = 2; i*i <=n ;i++){
		    if(!isPrime[i])continue;
		    for(long long j = i*i; j <= n ; j+=i){
			    isPrime[j]=false;
		    }
	    }
	    for(auto i:isPrime) cont+=i;
	    return cont;
    }
    long long fact(int num, long long modulo){
	    long long res = 1;
	    for(long long i = 1; i <=num; i++){
		    res = (res*i)%modulo;
	    }
	    return res;
    }
    int numPrimeArrangements(int n) {
        long long modulo = 1e9+7;
	int num_primes = computePrimes(n);
	return (fact(num_primes,modulo)*fact(n-num_primes, modulo))%modulo;
    }
};
