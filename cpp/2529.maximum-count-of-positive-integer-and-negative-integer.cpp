class Solution {
public:
    int maximumCount(vector<int>& nums) {
	    int mid1 = upper_bound(nums.begin(), nums.end(), 0)-nums.begin();
	    int mid2 = lower_bound(nums.begin(), nums.end(), 0)-nums.begin();
	    ///  n n n n 0 0 0 0 p p p p n
	    ///  0 0 0 0                 
	    ///  p p p 
	    ///  1    
	    int n = nums.size();
	    return max(n-mid1, mid2);
    }
};
