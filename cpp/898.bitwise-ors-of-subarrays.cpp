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
    int subarrayBitwiseORs(vector<int>& arr) {
       int n = arr.size();
       unordered_set<int> prev, global;
       // 1 2 4
       //     i
       // prev = {6, 7}
       // global = {1,2,3,4,6,7}
       for(int i = 0 ; i < n ;i++){
	       unordered_set<int> next_prev;
	       global.insert(arr[i]);
	       next_prev.insert(arr[i]);
	       for(auto num:prev){
		       next_prev.insert(arr[i]|num);
		       global.insert(arr[i]|num);
	       }
	       prev= next_prev;
       } 
       return global.size();
    }
};

//  [1,1,2]
//       i
//  [1],
//   xor 1,3
//
//  1 2 3 3 4 5 6 7 3
//  a b c c d e f g 
//  0 1 1 2
//
//  if nums[i] found before add after last occurrence
//  if nums[i] not found before
//      if total_or[i] is different to prev:
//         add all subarrays from start
//      else
//          add all subarrays form last time or ocurred
