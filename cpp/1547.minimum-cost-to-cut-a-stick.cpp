class Solution {
public:
    
    int dfs(vector<int> &cuts, int l, int r, vector<vector<int> > &memo){
	if(l+1==r) return 0;//cuts[r]-cuts[l]; //base case keep it alone
	if(memo[l][r]!=-1)return memo[l][r];
	int res = INT_MAX;
	for(int k = l+1; k < r; k++){//inner stick
		res = min(res, 
				dfs(cuts, l, k, memo)+
				dfs(cuts, k, r, memo));
	}
	return memo[l][r] = (res+cuts[r]-cuts[l]);
    }
    int solve(int n, vector<int> &cuts){
	sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
	cuts.push_back(n);
	vector<vector<int> > memo(cuts.size(), vector<int> (cuts.size(),-1));
	return dfs(cuts, 0, cuts.size()-1, memo);
    }
    int solve_bottom_up(int n, vector<int> &cuts){
	cuts.push_back(0);
	cuts.push_back(n);
	sort(cuts.begin(), cuts.end());
	int m = cuts.size();
	vector<vector<int> > dp(cuts.size(), vector<int> (m, 0));
	for(int l=2; l< m; l++){
		for(int i = 0; i+l < m; i++){
			int j = i+l;
			dp[i][j] = INT_MAX;
			for(int k = i+1; k <j; k++){
				dp[i][j] = min(dp[i][j],
						dp[i][k]+
						dp[k][j]+
						cuts[j]-cuts[i]);
			}
		}
	}
	return dp[0][m-1];
    }
    int minCost(int n, vector<int>& cuts) {
	    return solve_bottom_up(n, cuts);
	    return solve(n, cuts);
    }
};
