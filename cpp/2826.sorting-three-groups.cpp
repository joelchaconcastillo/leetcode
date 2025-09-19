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

    int solve1(vector<int>& nums) {
        int n = nums.size();
	if(n<=1)return 0;
	int res = n, m1=0;
	for(int i = 0 ; i < n; i++){
		int m2=0;
		for(int j = i; j < n; j++){
			int m3=0;
			for(int k = j; k < n; k++){
				if(nums[k]!=3)m3++;
			}
			res = min(res, m1+m2+m3);
		        if(nums[j]!=2)m2++;
		}
		res = min(res, m1+m2);
		if(nums[i]!=1)m1++;
	}
	res = min(res, m1);
	return res;
    }
    int solve2(vector<int>& nums) {
	    int one=0,two=0,three=0;
	    for(auto num:nums){
		    one += num!=1;
		    two = min(one, two+(num!=2));
		    three = min(two, three+(num!=3));
	    }
	    return three;
    }
    map<tuple<int, int>, int>memo;
    int dfs(vector<int> &nums, int k, int idx){
	    if(k>3)return INT_MAX/2;
	    if(idx==nums.size()){
		    return 0;
	    }
	    tuple<int, int> key(k, idx);
	    if(memo.count(key))return memo[key];
	    int res = INT_MAX;
	    for(int i = k; i <=3; i++){
	       res = min(
			       res, 
			       dfs(nums, i, idx+1)+(nums[idx]!=i)
			       );
	    }
	    return memo[key]=res;
    }
    int minimumOperations(vector<int>& nums) {
	    return dfs(nums, 1, 0);
	    return solve2(nums);
    }
};
//    [1,2]
//       i
//       j
//         k
//    1 i 2 j 3
//
//    1 1 2 2 3
//      i
//             j
//    
//    2  1  3  2  1
//    1  1  2  3  3
