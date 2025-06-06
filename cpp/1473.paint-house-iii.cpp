class Solution {
public:
#define INT_MAX 100000000
    int dp(vector<int> &houses, vector<vector<int> > &cost, int target, int idx, int group, vector<vector<vector<int>> > &memo){
	  if(target < 0) return INT_MAX;
	  if(idx==houses.size()){
	     if(target!=0) return INT_MAX;
	     return 0;
	  }
	  if(memo[idx][target][group]!=-1)return memo[idx][target][group];
	  if(houses[idx]!=0) return dp(houses, cost, target-(group!=houses[idx]), idx+1, houses[idx], memo);
	  int res = INT_MAX;
          for(int i = 0; i < cost[idx].size(); i++){
	       res = min(res, dp(houses, cost, target-(group!=(i+1)), idx+1, i+1, memo)+cost[idx][i]);
	  }
	  return memo[idx][target][group] = res;
    }
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
	vector<vector<vector<int>> > memo(m, vector<vector<int>> (target+1,vector<int>(n+2,-1)));
	auto res = dp(houses, cost, target, 0, n+1, memo);
	if(res == INT_MAX) return -1;
	return res;
    }
    int solve2(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
	vector<vector<vector<int>> > _dp(m+1, vector<vector<int>> (target+1,vector<int>(n+1,INT_MAX)));
	//base cases
        if(houses[0]!=0){
	   _dp[1][1][houses[0]] = 0;
	}else{
	   for(int c = 0; c < n; c++) 
	     _dp[1][1][c+1] = cost[0][c];
	}

	for(int wall = 1; wall <m; wall++){
	   for(int t = 1; t <= target; t++){
	      for(int prev_c = 1; prev_c <=n; prev_c++){
		  if(_dp[wall][t][prev_c]==INT_MAX)continue;
		  if(houses[wall]!=0){
		     int next_t = t+(houses[wall]!=prev_c);
		     if(next_t > target)continue;
		     _dp[wall+1][next_t][houses[wall]] = min(
				     _dp[wall+1][next_t][houses[wall]],
				     _dp[wall][t][prev_c]);
		  }else{
		     for(int c = 1; c<=n; c++){
			 int next_t = t+(c!=prev_c);
			 if(next_t > target)continue;
			 _dp[wall+1][next_t][c] = min(
					 _dp[wall+1][next_t][c],
					 _dp[wall][t][prev_c]+cost[wall][c-1]
					 );
		     }
		  }
	      }
	   }
	}	
	int res = INT_MAX;
	for(int c = 1; c <=n; c++) res = min(res, _dp[m][target][c]);
	if(res==INT_MAX)return -1;
	return res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        return solve2(houses, cost, m, n, target);	    
        return solve(houses, cost, m, n, target);	    
    }
};
