class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, vector<int>> > > memo;
    vector<int> dfs(vector<int> &piles, int i, int M, int player){
	    if(i==piles.size()) return {0,0};
	    if(memo.count(i) && memo[i].count(M) && memo[i][M].count(player)) return memo[i][M][player];
	    int sum = 0;
	    vector<int>res(2,0);
	    for(int x = 0; x < 2*M && i+x<piles.size(); x++){
		    sum+=piles[i+x];
		    auto tmp = dfs(piles, x+i+1, max(M, x+1), 1-player);
		    tmp[player]+=sum;
		    if(tmp[player] > res[player])res=tmp;
	    }
	    return memo[i][M][player] = res;
    }
    int solve(vector<int> &piles){
	    memo.clear();
	    auto res = dfs(piles, 0, 1, 0);
	    return res[0];
    }
    int helper(vector<int> &piles, int i, int M, vector<vector<int>> &dp, vector<int> &sufixSum){
	    if(i == piles.size())return 0;
	    if(2*M+i >= piles.size()) return sufixSum[i];
	    if(dp[i][M]!=-1)return dp[i][M];
	    int res = INT_MAX;
	    for(int x = 1; x<= 2*M; x++){
		    res = min(res, helper(piles, i+x, max(x,M),dp, sufixSum));
	    }
	    return dp[i][M] = sufixSum[i]-res;
    }
    int solve2(vector<int> &piles){
	    if(piles.empty()) return 0;
	    int n = piles.size();
	    vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
	    vector<int> sufixSum(n,0);
	    int prev = 0;
	    for(int i = n-1; i >=0; i--){
		    sufixSum[i] += piles[i]+prev;
		    prev += piles[i];
	    }
	    return helper(piles, 0, 1, dp, sufixSum);
    }
    int stoneGameII(vector<int>& piles) {
	    return solve2(piles);
	    return solve(piles);
    }
};
