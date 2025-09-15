class Solution {
public:

    int smallestRangeII(vector<int>& nums, int k) {
	    sort(nums.begin(), nums.end());
	    int n = nums.size(), res = nums.back()-nums.front();
	    for(int i = 0 ;i+1<n; i++){
		int maxv=  max(nums[i]+k, nums.back()-k);
		int minv = min(nums[i+1]-k, nums.front()+k);
		res = min(res, maxv-minv);
	    }
	    return res;
    }
};
