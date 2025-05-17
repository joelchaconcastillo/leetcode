class Solution {
public:
    int solve(int n){
	vector<int> options;
	for(int i = 0 ; i < 3; i++){
	   for(int j = 0 ; j < 3; j++){
	      for(int k = 0; k < 3; k++){
		    if(i==j || j==k)continue;
		    int color = 0;
		    color |= (1<<(i));
		    color |= (1<<(j+3));
		    color |= (1<<(k+6));
		    options.push_back(color);
	      }
	   }
	}
	int m = options.size();
	const int MOD = 1e9+7;
	vector<vector<long long> > dp(n, vector<long long> (m, 0));
	for(int j = 0 ; j < m; j++)dp[0][j]=1;
	for(int i  = 1; i < n; i++){
	   for(int j =  0; j <m; j++){ 
		   for(int k = 0; k <m; k++){
			   if((options[j]&options[k]) != 0)continue;
			   dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
		   }
	   }
	}
	int res = 0;
	for(int j = 0 ; j <m; j++) res= (res+dp.back()[j])%MOD;
	return res%MOD;
    }
    int solve2(int n){
	long long a121 = 6, a123 = 6, b121=0, b123=0;
	const int MOD = 1e9+7;
	while(n-- > 1){
		b121 = a121*3 + a123*2;
		b123 = a121*2 + a123*2;
		a121 = b121%MOD;
		a123 = b123%MOD;
	}
	return (a121+a123)%MOD;
    }
    int numOfWays(int n) {
	    return solve2(n);
    }
};
