class Solution {
public:
    vector<int> solve(vector<int> &nums1, vector<int> &nums2){
	    int n = nums1.size();
	    vector<int> res(n);
	    vector<pair<int, int>> n1, n2;
	    for(int i = 0 ; i < n ; i++){
		    n1.push_back({nums1[i], i});
		    n2.push_back({nums2[i], i});
	    }
	    sort(n1.begin(), n1.end());
	    sort(n2.begin(), n2.end());
	    for(int i = 0 ; i < n ; i++){
		    res[n1[i].second] = n2[i].second;
	    }
	    return res;
    }
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
	    return solve(nums1, nums2);
    }
};
