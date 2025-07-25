class Solution {
public:
    int helper(vector<vector<int>> costs, int i, int prevC, map<tuple<int, int>, int> &memo){
	    if(i == costs.size()){
		    return 0;
	    }
	    tuple<int, int> key(i, prevC);
	    if(memo.count(key)) return memo[key];
	    int res = INT_MAX;
	    for(int j = 0 ;j < 3; j++){
		    if(prevC == j) continue;
		    res = min(res, helper(costs, i+1, j, memo)+costs[i][j]);
	    }
	    return memo[key] = res;
    }
    int solve(vector<vector<int> > &costs){
	    int n = costs.size();
	    map<tuple<int, int>, int> memo;
	    return helper(costs, 0, -1, memo);
    }
    int solve2(vector<vector<int> > &costs){
	    vector<int> dp(3);
	    int n = costs.size();
	    dp[0] = costs[0][0];
	    dp[1] = costs[0][1];
	    dp[2] = costs[0][2];
	    for(int i = 1; i < n; i++){
		 auto tmp = dp;
		 tmp[0] = min(dp[1]+costs[i][0], dp[2]+costs[i][0]);
		 tmp[1] = min(dp[0]+costs[i][1], dp[2]+costs[i][1]);
		 tmp[2] = min(dp[0]+costs[i][2], dp[1]+costs[i][2]);
		 dp = tmp;
	    }
	    return *min_element(dp.begin(), dp.end());
    }
    int minCost(vector<vector<int>>& costs) {
	    return solve2(costs);
	    return solve(costs);
    }
};
