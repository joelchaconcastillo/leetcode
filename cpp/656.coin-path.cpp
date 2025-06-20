class Solution {
public:
    vector<int> solve(vector<int> &coins, int maxJump){
	    int n = coins.size();
	    vector<int> dp(n, 1000000);//min score, max taken
	    vector<int> parent(n, -1);
	    dp.back()=coins.back();
	    for(int i = n-2; i >= 0; i--){ // 1-1 --> 0
		    if(coins[i]==-1) continue;
		    for(int j = i+1; j <= min(n-1, i+maxJump); j++){//1
			    if(coins[j]==-1) continue;
			    if(dp[i] > dp[j]+coins[i]){
				    dp[i] = dp[j]+coins[i];
				    parent[i] = j;
			    }
		    }
	    }
	    vector<int> res;
	    int current = 0;
	    while( current!=-1){
		    res.push_back(current+1);
		    current = parent[current];
	    }
	    if(res.back()!=n)return {};
	    return res;
    }
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
	    return solve(coins, maxJump);
    }
};
