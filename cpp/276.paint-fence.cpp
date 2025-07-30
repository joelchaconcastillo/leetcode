class Solution {

public:

struct my_hash {
    size_t operator()(const tuple<int, int, int>& values) const {
        int a = get<0>(values);
        int b = get<1>(values);
        int c = get<2>(values);
        return hash<int>{}(a) ^ (hash<int>{}(b) << 1) ^ (hash<int>{}(c) << 2);
    }
};

	// dp[i] = # of ways to paint 0..i with k colors s.t. at most 2 consequtive items
	// f(i,last1,last2) = sum f(i,last1, last2)+1 with color c s.t. last1!=last2 && last2!=c && last1!=c
	// f(n, -, -)return 1
	//
    int helper(int n, int k, int prev1, int prev2, unordered_map<tuple<int, int, int>, int, my_hash> &memo){
	    if(n==0)return 1;
	    tuple<int, int, int>key(n, prev1, prev2);
	    if(memo.count(key))return memo[key];
	    int res = 0;
	    for(int c = 1; c<=k; c++){
		    if(c==prev1 && c==prev2)continue;
		    res += helper(n-1, k, prev2, c, memo);
	    }
	    return memo[key] = res;
    }
    int solve(int n, int k){
	    unordered_map<tuple<int, int, int>, int, my_hash>memo;
	    return helper(n, k, -1,-1,memo);
    }
    int solve2(int n, int k){
	    if(n==1)return k;
	    int prev_ways1 = k, prev_ways2=k*k;
	    for(int i=3; i <=n; i++){
		    int ways = (k-1)*prev_ways2+(k-1)*prev_ways1;
		    prev_ways1 = prev_ways2;
		    prev_ways2 = ways;
	    }
	    return prev_ways2;
    }
    int numWays(int n, int k) {
	    return solve2(n, k);
	    return solve(n, k);
    }
};
