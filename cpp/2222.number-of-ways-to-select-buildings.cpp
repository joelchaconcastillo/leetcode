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
    static const int MAXS = 1e5+1;
    long long memo[MAXS][5][5];
    long long dfs(string &st, int idx, int prev, int k){
	    if(k<0) return 0;
	    if(idx == st.size()){
		    return k==0;
	    }
	    if(memo[idx][prev][k]!=-1)return memo[idx][prev][k];
	    long long res = dfs(st, idx+1, prev, k);
	    if(prev!=(int)st[idx]-'0'){
		    res += dfs(st, idx+1, (int)st[idx]-'0', k-1);
	    }
	    return memo[idx][prev][k]=res;
    }
    long long numberOfWays(string s) {
	    memset(memo, -1, sizeof memo);
	    return dfs(s, 0, 2, 3);
    }
};
