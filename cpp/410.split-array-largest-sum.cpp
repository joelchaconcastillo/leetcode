class Solution {
public:
    vector<vector<int> > memo; 
    int dp1(vector<int> &nums, int i, int k){
	if( k < 0 ) return INT_MAX;
	if( i == nums.size()){
	    if(k == 0 )return 0;
	    return INT_MAX;
	}
	if(memo[i][k]!=-1)return memo[i][k];
	int res = INT_MAX, current_sum = 0;
	for(int l = i ; l < nums.size(); l++){
	   current_sum += nums[l];
	   res  = min(res, max(dp1(nums, l+1, k-1), current_sum));
	}
	return memo[i][k] = res;
    }
    int solve(vector<int> &nums, int k){
	int n = nums.size();
	memo.assign(n+1, vector<int> (k+1, -1));
	return dp1(nums, 0, k);
    }
    int splitArray(vector<int>& nums, int k) {
	return solve(nums, k);
    }
};
