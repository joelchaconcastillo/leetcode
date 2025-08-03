class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs(int n, int k){
	    if(n==0)return 0;
	    if(n==1)return 1;
	    if(k==1)return n;
	    if(memo.count(n) && memo[n].count(k))return memo[n][k];
	    int res = INT_MAX/2;
	    for(int x = 1; x <=n; x++){
		    int broken = dfs(x-1 , k-1);
		    int not_broken = dfs(n-x, k);
		    int worst = max(broken, not_broken)+1;
		    res = min(worst, res);
	    }
	    return memo[n][k] = res;
    }
    int solve(int n){
	    return dfs(n, 2);
    }
    int solve2(int n){
	    return ceil(sqrt(8*n))/2;
    }
    int twoEggDrop(int n) {
	    return solve2(n);
	    return solve(n);
    }
};
//  100
//                50  75
// 16 16
//       30     40
//         33 37
//           
