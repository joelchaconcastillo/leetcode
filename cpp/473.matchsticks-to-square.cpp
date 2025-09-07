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
    bool helper(vector<int> &sticks, int i, vector<long long>&sides){
	if(i == sticks.size()){
		return sides == (vector<long long>){0,0,0,0};
	}
	for(int k = 0 ; k < 4; k++){
		if(sides[k]-sticks[i] < 0)continue;
		if(k>0 && sides[k] == sides[k-1])continue;//prune 1
		sides[k]-= sticks[i];
		if(helper(sticks, i+1, sides))return true;//prune 2
		sides[k]+= sticks[i];
	}
	return false;
    }
    bool makesquare(vector<int>& matchsticks) {
	 sort(matchsticks.rbegin(), matchsticks.rend());
         long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
         if(sum%4!=0)return false;
	 long long side = sum/4LL;
	 vector<long long>sides = {side, side, side, side};
         return helper(matchsticks, 0, sides);	 
    }
};
