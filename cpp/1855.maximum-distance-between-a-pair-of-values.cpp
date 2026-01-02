class Solution {
public:
    
    int solve2(vector<int>& nums1, vector<int>& nums2) {
	    int n = nums1.size(), m = nums2.size();
	    int i = 0, j = 0, res=0;
	    while(i<n && j < m){
		    if(nums1[i] <= nums2[j]){
			    res = max(res, j-i);
			    j++;
		    }else{
			    i++;
		    }

	    }
	    return res;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
	    return solve2(nums1, nums2);
    }
    int solve1(vector<int>& nums1, vector<int>& nums2) {
        for(auto &i:nums1) i=-i;	    
        for(auto &i:nums2) i=-i;
	int res = 0;
	for(int i = 0 ;i < nums1.size(); i++){
		int pos = upper_bound(nums2.begin()+i, nums2.end(), nums1[i])-nums2.begin();
			pos--;
		       	res = max(res, pos-i);
	}
	return res;
    }
};
