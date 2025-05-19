class Solution {
public:
    const int MOD = 1e9+7;
    int dp(int n, int current_state, vector<int> &options, map<tuple<int, int>, int > &memo){
	  if(n==0)return 1;
	  if(memo.count({n, current_state}))return memo[{n, current_state}]%MOD;
	  int res = 0;
	  for(auto next_state:options){
		  if(next_state & current_state)continue;
		  res = (res+dp(n-1, next_state, options, memo))%MOD;
	  }
	  return memo[{n, current_state}] = res%MOD;
    }
    void fill_options(int m, int current_state, int prev_color, vector<int> &options){
	if(m==0){
		options.push_back(current_state);
		return;
	}
        for(int color = 0; color < 3; color++){
	  if(prev_color == color)continue;
	  int next_state =  current_state| (1<<(3*m+color));
          fill_options(m-1, next_state, color, options);
       }
    }
    int solve1(int m, int n){
	vector<int> options;
        map<tuple<int, int>, int > memo;
	fill_options(m, 0, -1, options);
	return dp(n, 0, options, memo)%MOD;
    }
    int solve2(int m, int n){
	vector<int> options;
	fill_options(m, 0, -1, options);
	unordered_map<int, int> DP;
	for(auto i:options)DP[i]=1;
	for(int i = 1; i < n; i++){
	   unordered_map<int, int> nextDP;
	   for(auto state:DP){
	       for(auto next_state:options){
		    if(state.first & next_state)continue;
		    nextDP[next_state] = (nextDP[next_state] + state.second)%MOD;
	       }
	   }
	   DP = nextDP;
	}
	int res =  0;
	for(auto ii:DP) res = (res+ii.second)%MOD;
	return res;
    }
    int colorTheGrid(int m, int n) {
	return solve2(m, n);
	return solve1(m, n);
    }
};
