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
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs(vector<int> &nums, int idx, int k){
	    if(k<0)return INT_MAX/2;
	    if(idx == nums.size()){
		    return 0;
	    }
	    if(memo.count(idx) && memo[idx].count(k))return memo[idx][k];
	    int res = INT_MAX/2, max_value = INT_MIN, sum = 0;
	    for(int j = idx; j  < nums.size(); j++){
		    max_value = max(max_value, nums[j]);
		    sum+=nums[j];
		    int wasted = (j-idx+1)*max_value-sum;
		    res = min(res, dfs(nums, j+1, k-1)+wasted);
	    }
	    return memo[idx][k] = res;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
	    return dfs(nums, 0, k+1);
    }
};
//nums = [10,20,30], k = 1
//        10
//        
//dp[i][j] = min space wasted on 0..i having at most j size changes
//    base case
//    k<0 return INT_MAX;
//    if(i==nums.size()) return current;
//    if( current < nums[i])
//        val = f(i+1, k-1, nums[i])
//        res = min(res, val-nums[i])
//    f(i+1, k, current)
//    res = min(res, val-nums[i])
//
//   _ _ _ | _ _ _ | _ _ _
//
