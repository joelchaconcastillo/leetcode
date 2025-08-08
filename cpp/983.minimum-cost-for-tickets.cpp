class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int> &days, vector<int>&costs, vector<int> &durations, int i){
	    if(i == days.size()){
		    return 0;
	    }
	    if(memo.count(i))return memo[i];
	    int res = INT_MAX/2;
	    for(int k = 0 ; k < 3; k++){
	       int j = i;
	       while( j < days.size() && days[j] < days[i]+durations[k])j++;
	       res = min( res, dfs(days, costs, durations, j)+costs[k]);
	    }
	    return memo[i] = res;
    }
    int solve2(vector<int> &days, vector<int> &costs){
	    int n = days.size(), m = costs.size();
	    vector<int> durations = {1,7,30};
	    return dfs(days, costs, durations, 0);
    }
    int solve(vector<int> &days, vector<int> &costs){
	    int n = days.size(), m = costs.size();
	    vector<int> dp(n+1, 0);
	    vector<int> durations = {1,7,30};
	    for(int i = n-1; i >=0; i--){
		    int res = INT_MAX;
		    for(int k = 0 ; k <3; k++){
			    //int j = i;
//			    while(j<n && days[j] < days[i]+durations[k]) j++;
			    int j = lower_bound(days.begin()+i, days.end(), days[i]+durations[k])-days.begin();
			    res = min(res, costs[k]+dp[j]);
		    }
		    dp[i]=res;
	    }
	    return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
	    return solve(days, costs);
	    return solve2(days, costs);
    }
};
