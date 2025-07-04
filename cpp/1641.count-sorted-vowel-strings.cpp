class Solution {
public:
    int dfs(int n, int k, vector<vector<int>> &memo){
	if(n==0){
	   return 1;
	}
	if(memo[n][k]!=-1)return memo[n][k];
	int res = 0;
	for(int i = k; i >=0; i--){
	  res += dfs(n-1, i, memo);
	}
	return memo[n][k] = res;
    }
    int solve(int n){
	vector<vector<int> > memo(n+1, vector<int> (5,-1));
	auto res = dfs(n, 4, memo);
	return res;
    }
    int solve2(int n){
	    // 1: 5 --> 5
	    // 2: 15 --> 5+4+3+2+1
	    // 3:    --> 15+14+13 ....
	    // C(5, n) --> 
	    return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
    int countVowelStrings(int n) {
	    return solve2(n);
	    return solve(n);
    }
};
