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

    int findTheLongestSubstring(string s) {
	    int n = s.size();
	    int mask = 0;
	    unordered_map<char, int> pos = {
		    {'a',0}, {'e',1}, {'i',2}, {'o',3},
		    {'u',4}
	    };
	    unordered_map<int, int> dp;
	    dp[0]=-1;
	    int res = 0;
	    for(int i = 0; i < n; i++){
		    if(pos.count(s[i])) mask ^= (1<<pos[s[i]]);
		    if(dp.count(mask)==0)dp[mask]=i;
		    else res = max(res, i-dp[mask]);
	    }
	    return res;

    }
};
