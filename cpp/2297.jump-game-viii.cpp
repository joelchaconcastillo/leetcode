class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& costs) {
	    vector<int> st1, st2;
	    int n = nums.size();
	    vector<long long> dp(n, LLONG_MAX);
	    dp[0]=0;
	    for(int i = 0; i<n;i++){
		    while(!st1.empty() && nums[i] >= nums[st1.back()]){
			    dp[i] = min(dp[i], dp[st1.back()]+costs[i]);
			    st1.pop_back();
		    }
		    while(!st2.empty() && nums[i] < nums[st2.back()]){
			    dp[i] = min(dp[i], dp[st2.back()]+costs[i]);
			    st2.pop_back();
		    }
		    st1.push_back(i);
		    st2.push_back(i);
	    }
	    return dp.back();
    }
    long long minCost(vector<int>& nums, vector<int>& costs) {
	 return solve(nums, costs);   
    }
};
