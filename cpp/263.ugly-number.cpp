class Solution {
public:
    bool isUgly(int n) {
	if(n<=0)return false;
	vector<long long> primes={2,3,5};
	for(auto prime:primes){
            while(n%prime==0){
	        n/=prime;
	     }
	}
	return n==1;
    }
};
