class Solution {
public:
    int res = 0;
    bool isSquare(long long n){
	    long long r = sqrt(n);
	    return r*r == n;
    }
    int memo[30][30][2^13];
    int dfs(vector<int> &nums, int k, long long taken, int prev){
	    if(k==nums.size()){
		    return 1;
	    }
//	    if(memo[k][taken][prev]!=-1)return memo[k][taken][prev];
	    int res = 0;
	    for(int i = 0 ; i < nums.size(); i++){
		    int mask = (1<<i);
		    if(mask&taken)continue;
		    if(prev!=-1 && !isSquare(prev+nums[i]))continue;
		    if (i > 0 && nums[i] == nums[i-1] && !(taken & (1 << (i-1)))) continue;

		    taken |=mask;
		    res += dfs(nums, k+1, taken, nums[i]);
		    taken ^=mask;
	    }
	    return res;//return memo[k][taken][prev]=res;
    }
    int numSquarefulPerms(vector<int>& nums) {
	    sort(nums.begin(), nums.end());
	    return dfs(nums, 0, 0LL, -1);
    }
};
