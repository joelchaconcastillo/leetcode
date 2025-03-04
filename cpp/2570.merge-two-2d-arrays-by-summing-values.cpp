class Solution {
public:
    vector<vector<int>>solve(vector<vector<int>> &nums1, vector<vector<int>> &nums2){
	map<int, int> data;
	for(auto i:nums1)data[i[0]]+=i[1];
	for(auto i:nums2)data[i[0]]+=i[1];
	vector<vector<int>> res;
	for(auto ii:data)res.push_back({ii.first, ii.second});
	return res;
    }
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
	return solve(nums1, nums2);
    }
};
