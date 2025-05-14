class Solution {
public:
    map<tuple<int, int>, int>memo;
    const int MOD = 1e9+7;
    int dp(int current, vector<int> &locations, int finish, int fuel){
	if(fuel<0)return 0;
	if(memo.count({current, fuel}))return memo[{current, fuel}];
	int res = current==finish;
	for(int i = 0; i < locations.size(); i++){
	   if(i==current)continue;
	   int delta = abs(locations[current]-locations[i]);
	   res += dp(i, locations, finish, fuel-delta);
	   res %=MOD;
	}
	return memo[{current, fuel}] = (res%MOD);
    }
    int solve_top_down(vector<int> &locations, int start, int finish, int fuel){
	memo.clear();
        return dp(start, locations, finish, fuel); 
    }
    int solve_bottom_up(vector<int> &locations, int start, int finish, int fuel){
	    int n = locations.size();
	    vector<vector<int> > dp(n,vector<int> ( fuel+1,0));
	    for(int i = 0 ; i < fuel+1; i++)
	    dp[start][i] = 1;
	    for(int j = 1; j <= fuel; j++){
	            for(int i  = 0 ; i < n; i++){
			    for(int k = 0 ; k < n; k++){
			       if(k==i)continue;
			       int delta = abs(locations[i]-locations[k]);
			       if(j-delta <0)continue;
			       dp[i][j] += dp[k][j-delta];
			       dp[i][j] %=MOD;
			    }
		    }
	    }
	    return dp[finish][fuel];
    }
    int solve_optimal(vector<int> &locations, int start, int finish, int fuel){
	    int n = locations.size();
	    vector<vector<int> > left(n, vector<int> (fuel+1, 0));
	    vector<vector<int> > right(n, vector<int> (fuel+1, 0));
	    start = locations[start], finish = locations[finish];
	    sort(locations.begin(), locations.end());
	    for(int i =  0; i <n ; i++){
		    if(locations[i] == start) start = i;
		    if(locations[i] == finish) finish = i;
	    }
	    for(int f = 1; f <= fuel; f++){
		 for(int i = 0 ; i+1 < n; i++){
		    int delta = locations[i+1]-locations[i];
		    if(f>delta) left[i][f] = (right[i+1][f-delta]+2*left[i+1][f-delta]%MOD)%MOD;
		    else if(f==delta && start == (i+1)) left[i][f] = 1;
		 }
		 for(int i = 1 ; i < n; i++){
		    int delta = locations[i]-locations[i-1];
		    if(f>delta) right[i][f] = (left[i-1][f-delta]+2*right[i-1][f-delta]%MOD)%MOD;
		    else if(f==delta && start == (i-1)) right[i][f] = 1;
		 }
	    }
	    int res = (start==finish);
	    for(int i = 1; i <= fuel; i++) res = (  (res+left[finish][i])%MOD + right[finish][i]%MOD);
	    return res%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
	    return solve_optimal(locations, start, finish, fuel);
	    return solve_bottom_up(locations, start, finish, fuel);
	    //return solve_top_down(locations, start, finish, fuel);
    }
};
/*
 *
      0  1  2  3  4  5  6  7
 * 3  1  1  1  1  1  1  1  1
   2  0  1  1  1  2  2  3  
   4  0  0  1  1  2  3  1+2+2+
   6  0  0  0  1  2  3
 * 8  0  0  0  0  0  2
dp [i][f] = dp[j][f-|c[i]-c[j]|]
  where dp[i][f] --> all paths from start to i having a fuel 'f'
 * */
