class Solution {
public:
    int solve_optimized(vector<int> &nums, int k){
	int n = nums.size();
	vector<int> dp(n, 0);
	deque<int> dq;
	for(int i = 0; i < n; i++){
	   if(!dq.empty() && i-dq.front()>k)dq.pop_front();
	   if(!dq.empty()) dp[i] = max(0, dp[dq.front()]);
	   dp[i]+=nums[i];
	   while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
	   dq.push_back(i);
	}
	return *max_element(dp.begin(), dp.end());
    }
    int solve(vector<int> &nums, int k){
	int n = nums.size(), res = nums[0];
	priority_queue<pair<int, int> > pq;
	pq.push({nums[0], 0});
	for(int i = 1; i <n; i++){
	   while(!pq.empty() && i-pq.top().second >k)pq.pop();
	   int current = max(0, pq.top().first)+nums[i];//kadane max 
	   res = max(res, current);
	   pq.push({current, i});
	}
	return res;
    }
    // 0   1   2   3   4
    //[10  2  -10  5  20]
    // 10  12 -8   5  25
    // 10  12  0   17 25
    int constrainedSubsetSum(vector<int>& nums, int k) {
	return solve_optimized(nums, k);
	return solve(nums, k);
    }
};
