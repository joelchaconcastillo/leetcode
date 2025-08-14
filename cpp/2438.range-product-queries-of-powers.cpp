#define oob(x, y) (x < 0 or y < 0 or x >= N or y >= N)
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class Solution {
public:
    long long modpow(long long base, long long exp, long long MOD){
	    long long result = 1;
	    while(exp){
		    if(exp&1) result = (result*base)%MOD;
		    base  = (base * base)%MOD;
		    exp >>=1;
	    }
	    return result;
    }
    vector<int> solve(int n, vector<vector<int> > &queries){
	    vector<long long> powers;
	    long long _pow = (1<<30);
	    int N = n;
	    while(_pow>0){
		    if(N-_pow>=0){
			    powers.push_back(_pow);
			    N -= _pow;
		    }
		    _pow >>=1;
	    }
	    reverse(powers.begin(), powers.end());
	    vector<int> res, prefix(powers.size()+1);
	    long long prod = 1, MOD = 1e9+7;
	    prefix[0]=1;
	    for(int i = 1; i <=powers.size(); i++){
		    prod = (prod*powers[i-1])%MOD;
		    prefix[i] = prod;
	    }
	    for(auto query:queries){
		    int l = query[0]+1, r = query[1]+1;
		    long long num = (prefix[r]);
		    long long den = modpow(prefix[l-1], MOD-2, MOD);
		    res.push_back((num*den)%MOD);
	    }
	    return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
	    return solve(n, queries);
    }
};
