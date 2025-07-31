class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size();
	    vector<int> dp(n, INT_MIN);
	    dp[0]=0;
	    for(int i = 0 ; i < n; i++){
		    for(int j = i+1; j<n; j++){
			    dp[j] = max(dp[j], dp[i]+(j-i)*nums[j]);
		    }
	    }
	    return dp.back();
    }
    int solve2(vector<int> &nums){
	    int n = nums.size(), res = 0;
	    pair<int, int> largest(nums.back(),n-1);
	    for(int i = n-2; i>0; i--){
		    if(nums[i] > largest.first){
			    res += (largest.second-i)*largest.first;
			    largest = {nums[i], i};
		    }
	    }
	    res += largest.second*largest.first;
	    return res;
    }
    int maxScore(vector<int>& nums) {
	    return solve2(nums);
	    return solve(nums);
    }
};
