class Solution {
public:
	// time: O(n*k log (k*n)) -- >10^5*10^2 log ( 10^7 )
	// --> 10^7 log (10^2) --> 
    int solve(int n, vector<int> &primes){
	set<long long> super_ugly;
	super_ugly.insert(1);
	for(int i = 1 ; i < n; i++){
	   long long _current = *super_ugly.begin();
	   long long _back = *prev(super_ugly.end());
	   super_ugly.erase(_current);
	   for(auto i:primes){
		if(super_ugly.size() > n  && _current*i > _back)continue;
		super_ugly.insert(_current*i);
	   }
	}
	return *super_ugly.begin();
    }
    int solve2(int n, vector<int> &primes){
	 vector<long long> ugly(n, 1), idx((int)primes.size(), 0);
	 vector<long long> values(primes.begin(), primes.end());
	 for(int i = 1 ; i < n; i++){
	    long long min_val = *min_element(values.begin(), values.end());
	    ugly[i] = min_val;
	    for(int j = 0 ; j < values.size(); j++){
	        if( values[j] == min_val ){
		    idx[j]++;
		    values[j] = ugly[idx[j]]*primes[j];
		}
	    }
	 }
	 return ugly.back();
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
	//return solve(n, primes);
	return solve2(n, primes);
    }
};
/*
  
    n*log(k)


 * */
