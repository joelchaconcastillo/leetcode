class Solution {
public:
    vector<int> solve(vector<int> &nums, int k){
	    vector<int> res;
	    int n = nums.size(), maxv=0, idx=0;
	    for(int i = 0; i+k <= n; i++){ //k=1, n=2, i=1, --> 0, 
	       if(nums[i] > maxv){
		       maxv = nums[i];
		       idx = i;
	       } 
	    }
	    for(int i = idx; i < idx+k; i++) res.push_back(nums[i]);
	    return res;
    }
    vector<int> largestSubarray(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
