class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());	    
	if(nums.size()==1)return 0;
	int res = INT_MAX;
	// _ _
	//   i
	for(int i = k-1; i < nums.size(); i++){
		res = min(res, nums[i]-nums[i-k+1]);
	}
	if(res==INT_MAX)return 0;
	return res;
    }
};
