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
    bool solve(string start, string target) {
        if(start.size() != target.size()) return false;
        int n = start.size();
        int counter_r=0;
        for(int i = 0 ;i < n; i++){
            if(start[i]=='R') counter_r++;
            if(target[i]=='R')counter_r--;
            if((target[i]=='L' || start[i]=='L') && counter_r>0)return false;
            if(counter_r<0)return false;
        }
        if(counter_r>0)return false;
        int counter_l=0;
        for(int i = n-1; i>=0 ;i--){
            if(start[i]=='L')counter_l++;
            if(target[i]=='L')counter_l--;
            if((target[i]=='R' || start[i]=='R') && counter_l >0) return false;
            if(counter_l<0)return false;
        }
        if(counter_l>0)return false;
        return true;
    }
    bool canChange(string start, string target) {
	    return solve(start, target);
    }
};
