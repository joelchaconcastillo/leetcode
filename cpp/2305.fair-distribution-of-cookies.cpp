class Solution {
public:
    int helper(vector<int> &cookies, int k, int idx, vector<int> &total){
	    if(idx == cookies.size()){
		    return *max_element(total.begin(), total.end());
	    }
	    int res = INT_MAX;
	    for(int i = 0 ; i < k; i++){
		    total[i] += cookies[idx];
		    res = min(res, 
				    helper(cookies, k, idx+1, total));
		    total[i] -= cookies[idx];
	    }
	    return res;
    }
    int solve1(vector<int> &cookies, int k){
         vector<int> total(k,0);
	 return helper(cookies, k, 0, total);
    }
    int solve2(vector<int> &cookies, int k){
	    int n = cookies.size();
	    vector<int> sumPartition(1<<n, 0);
	    for(int mask = 0; mask < (1<<n); mask++){
		    for(int i = 0 ; i < n; i++){
			    if(mask & (1<<i) )
			    sumPartition[mask] += cookies[i];
		    }
	    }
	    vector<vector<int> > dp(k+1, vector<int> (1<<n, INT_MAX));
	    dp[0][0]=0;
	    for(int i = 1; i <= k; i++){
		    for(int mask = 0; mask < (1<<n); mask++){
			    for(int submask = mask; submask > 0; submask = (submask-1)&mask){
			      dp[i][mask] = min(dp[i][mask],
					      max(
						      dp[i-1][mask^submask], sumPartition[submask]
						      ));
			    }

		    }
	    }
	    return dp[k][(1<<n)-1];
    }
    int distributeCookies(vector<int>& cookies, int k) {
	    return solve2(cookies, k);
    }
};
/*
  [8,15,10,20,8] k =2
   8 8 10 15 20
   8 20 10
   8 15
 * */
