class Solution {
public:
    // time: O(n)
    // space: O(universe of nums)
    // elapsed time to resolve: 6 min.
    int solve(vector<int> &nums){
	int n = nums.size();
        int res = 0;
	unordered_map<int, int> freq;
	for(auto i:nums)freq[i]++;
	for(auto ii:freq){
	   if(!freq.count(ii.first+1)) continue;
	   res = max(res, ii.second+freq[ii.first+1]);
	}
	return res;
    }
    int findLHS(vector<int>& nums) {
	return solve(nums);
    }
};
