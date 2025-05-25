class Solution {
public:
    const int MOD = 1e9+7;
    int solve1(int n){
	if(n<=2)return n;
	vector<long long> dp(n+1);//dp[i] --> number of ways considering i itmes
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=5;
	for(int i = 4; i <= n; i++){
	   dp[i] = (dp[i-1]*2+dp[i-3])%MOD;
	}
	return dp[n];
			    //dp[i] = dp[i-1]+2*dp[i-2]+2*dp[i-3]-dp[i-4]
			    // 0:0
			    // 1:1  
			    // 2:2
			    // 3:5   2+2+1
			    // 4:11  
			    // 5:24  11+10+3
			    // 6:53  24+22+10-2-1
			    // 7:117 
			    // dp[i] = dp[i-1]+2*dp[i-2]-dp[i-2]

    }
    //case 1:  |
    //case 2:  =
    //case 3:  -|
    //case 4:  |_
    //case 5:  _
    //case 6:  -
    int dp(int i, vector<int>&tiles, unordered_map<int, int> &memo){
	  if(i == tiles.size()) return 1;
	  if(i==0){ //case 1
	      tiles.push_back(3) = 3; // 011
	      int res = dp(i+1, tiles, memo);
	      tiles.pop_back();
	      return res;
	  }
	  if(i>=1){
	     
	  }
    }
    int solve2(int n){
	vector<int> tiles(n, 0);
	unordered_map<int, int> memo;
	return dp(tiles);
    }
    int numTilings(int n) {
	return solve2(n);
	return solve1(n);
    }
};
