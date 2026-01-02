class Solution {
public:
    vector<bool> isPrime;
    void sieve(int n){
	    isPrime.assign(n+1, true);
	    isPrime[0] = isPrime[1] = false;
	    for(int i = 2; i*i <=n ;i++){
		    if(!isPrime[i])continue;
		    for(int j = i*i; j <= n; j+=i){
			    isPrime[j]=false;
		    }
	    }
    }
    int diagonalPrime(vector<vector<int>>& nums) {
	    sieve(4e6+1);
	    int maxP = INT_MIN;
	    int n = nums.size();
	    for(int i = 0 ;i  <n; i++){
		   if(isPrime[nums[i][i]]){
			   maxP = max(maxP, nums[i][i]);
		   }
		   if(isPrime[nums[i][n-i-1]]){
			    maxP = max(maxP, nums[i][n-i-1]);
		    }
	    }
	    if(maxP==INT_MIN)return 0;
	    return maxP;
    }
};
