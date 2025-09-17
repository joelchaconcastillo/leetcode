class Solution {
public:
    int memo[1001][1001];
    int dfs(vector<int> &prices, int idx, int rem_free){
	    if(idx == prices.size()){
		    return 0;
	    }
	    if(memo[idx][rem_free]!=-1)return memo[idx][rem_free];
	    int res = dfs(prices, idx+1, max(idx+1, rem_free-1))+prices[idx];
	    if(rem_free>0){
		    res = min(res,
				    dfs(prices, idx+1, rem_free-1));
	    }
	    return memo[idx][rem_free] = res;
    }
    int minimumCoins(vector<int>& prices) {
	    memset(memo, -1, sizeof memo);
	    return dfs(prices, 0, 0);
    }
};
