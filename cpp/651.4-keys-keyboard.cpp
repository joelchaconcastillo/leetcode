class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(int n){
	 if(memo.count(n))return memo[n];
	 if(n<=0)return 0;
         int res = 0;
	 res = max(dfs(n-1)+1, res);//press a
	 for(int i = 1; i <= n-3; i++){//ctrla+ctrlc+ctrlv
		 res = max(dfs(i)+dfs(i)*(n-i-2), res);
		 //dfs(i) + dfs(i)*(n-i-2)
         }
	 return memo[n] = res;
    }
    int solve(int n){
	    memo.clear();
	    return dfs(n);
    }
    int maxA(int n) {
	    return solve(n);
    }
};
