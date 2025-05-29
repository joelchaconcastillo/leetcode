class Solution {
public:
    int n;
    #define INT_MAX 1e9
    int dp(vector<int> &cost, vector<int> &time, int idx, int rem_walls, vector<vector<int> > &memo){
	if( rem_walls <= 0 )return 0;
	if( idx == n ) return INT_MAX;
	if(memo[idx][rem_walls] != -1) return memo[idx][rem_walls];
        int res = INT_MAX;
        //paid painter..	
	res = dp(cost, time, idx+1, rem_walls-1-time[idx], memo)+cost[idx],
	//free painter
	res = min(res, dp(cost, time, idx+1, rem_walls, memo));
	return memo[idx][rem_walls] = res;
    }
    int solve1(vector<int> &cost, vector<int> &time){
	n = cost.size();
	vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
	return dp(cost, time, 0, n, memo);
    }
    int solve2(vector<int> &cost, vector<int> &time){
	n = cost.size();
	vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
	//dp[i][j] --> min cost considering until i painter with j remaining walls
	for(int i = 1; i <=n; i++) dp[n][i]=INT_MAX;
	for(int i = n-1; i>=0 ; i--){
	   for(int remain = 1; remain <= n; remain++){
	      int paid = cost[i] + dp[i+1][max(0, remain-1-time[i])];
	      int free = dp[i+1][remain];
	      dp[i][remain] = min(paid, free);
	   }
	}
	return dp[0][n];
    }
    int solve3(vector<int> &cost, vector<int> &time){
	n = cost.size();
	vector<vector<int> > dp(n+1, vector<int> (n+1, INT_MAX));
	for(int i = 0; i<=n; i++)dp[i][0]=0;// we have zero cost for zero walls
	//dp[i][j] --> min cost considering until i painter with j remaining walls
	for(int i = 1; i <=n; i++){
	   for(int remain=1; remain<=n; remain++){
	      int paid = cost[i-1] + dp[i-1][max(0, remain-1-time[i-1])];
	      int free = dp[i-1][remain];
	      dp[i][remain] = min(paid, free);
	   }
	}
	return dp[n][n];
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
	return solve3(cost, time);
    }
};
/*
  cost = [1,2,3,2], time = [1,2,3,2]
  Output: 3
 * */
