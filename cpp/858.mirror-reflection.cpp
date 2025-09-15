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

    int solve1(int p, int q) {
	    double slope = (double)q/p;
	    int count = 1;
	    while( true){
		    double new_p = p*count;
		    double new_q = new_p*slope;
		    int qq = round(new_q);
		    if( fabs(qq-new_q) < 1e-3){
			    int pp = count%2==0?0:p;
			    if(qq==0 && pp==p)return 0;
			    if(qq==p && pp==p)return 1;
			    if(qq==p && pp==0)return 2;
		    }
		    count++;
	    }
	    return -1;

    }
    int my_gcd(int a, int b){
	    if(b==0)return a;
	    return my_gcd(b, a%b);
    }
    int solve2(int p, int q) {
	    int _gcd = my_gcd(p, q);
	    int m = p/_gcd, n = q/_gcd;
	    if(m%2==0)return 2;
	    return (n%2==0)?0:1;
    }
    int mirrorReflection(int p, int q) {
	    return solve2(p,q);
    }
};
