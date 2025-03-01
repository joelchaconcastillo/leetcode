class Solution {
public:
    /*
        time:  O(n1+n2)
        space: O(n1)
	elapsed time: 7 min.
     * */
    vector<int> solve(vector<int> &nums1, vector<int> &nums2){
	 int n1 = nums1.size(), n2 = nums2.size();
	 unordered_set<int> found;
	 vector<int>res;
	 for(auto i:nums1)found.insert(i);
	 for(auto i:nums2){
	    if(found.count(i)){
		    res.push_back(i);
		    found.erase(i);
	    }
	 }
	 return res;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       return solve(nums1, nums2); 
    }
};
