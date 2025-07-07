class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2){
	    int n1 = nums1.size(), n2 = nums2.size();
	    int res = 0 ;
	    for(int step=0; step < n1; step++){
		    int cnt = 0;
		    for(int i =  0; i < n2; i++){
			    cnt += (nums1[(i+step)%n1] == nums2[i]);
		    }
		    res = max(res, cnt);
	    }
	    return res;
    }
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
	    return solve(nums1, nums2);
    }
};
