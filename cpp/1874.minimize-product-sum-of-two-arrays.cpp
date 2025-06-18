class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2){
	    sort(nums1.begin(), nums1.end());
	    sort(nums2.begin(), nums2.end());
	    reverse(nums1.begin(), nums1.end());
	    int res = 0;
	    for(int i = 0 ;i  < nums1.size(); i++) res += nums1[i]*nums2[i];
	    return res;
    }
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
	    return solve(nums1, nums2);
    }
};
