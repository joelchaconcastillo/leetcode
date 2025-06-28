class Solution {
public:
    const long long MOD = 1e9+7;
    static const int MAX_N = 1e4+10, MAX_P = 15;
    int n, maxValue;
    int c[MAX_N+MAX_P][MAX_P+1];
    vector<int> ps[MAX_N];//prime counts..
    int sieve[MAX_N];
    vector<vector<int>>memo;
    long long dfs(int pos, int prev){
	    if(pos == n)return 1;
	    if(memo[n][prev] != -1)return memo[n][prev];
	    long long res = 0;
	    for(int mul=1; prev*mul <= maxValue; mul++){
		    res = (res+dfs(pos+1, prev*mul))%MOD;
	    } 
	    return res;
    }
    int solve(int n, int maxValue){
	    memo.assign(n+1, vector<int> (maxValue+1,-1));
	    this->n = n;
	    this->maxValue = maxValue;
	    int res = 0;
	    for(int i=1; i<=maxValue; i++){
		    res = (res+dfs(1, i))%MOD;
	    }
	    return res;
    }
    int solve_optimized(int n, int maxValue){
	    for(long long i = 2; i  < MAX_N; i++){//get lowest prime factor
		    if(sieve[i]!=0)continue;
		    for(int j = i; j <MAX_N; j+=i){
			    sieve[j] = i;
		    }
	    }
	    for(int i = 2; i < MAX_N; i++){//count number of prime factors
		    int x = i;
		    while(x>1){
			    int p = sieve[x];
			    int cnt = 0;
			    while(x%p == 0){
				    x/=p;
				    cnt++;
			    }
			    ps[i].push_back(cnt);
		    }
	    }
	    c[0][0]=1;
	    for(int i = 1;  i< MAX_N+MAX_P; i++){//just compute comb eqn
		    c[i][0] = 1;
		    for(int j = 1; j <= min(i, MAX_P); j++){
			    c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
		    }
	    }
	    long long res =  0;
	    for(int x = 1; x <=maxValue; x++){
		    long long mul = 1;
		    for(auto p: ps[x]){
			    mul = mul*c[n+p-1][p] % MOD;
		    }
		    res = (res+mul)%MOD;
	    }
	    return res;
    }
    int idealArrays(int n, int maxValue) {
	    return solve_optimized(n, maxValue);
    }
};
