class Solution {
public:
    vector<int> dfs(vector<int> &nums1, vector<int> &nums2, int k, int i, int j, vector<int> &path){
	    if(k==0){
		    return path;
	    }
	    vector<int> res;
	    if(i<nums1.size()){
		    path.push_back(nums1[i]);
		    res = max(res, dfs(nums1, nums2, k-1, i+1, j, path));
		    path.pop_back();
		    res = max(res, dfs(nums1, nums2, k, i+1, j, path));
	    }
	    if(j<nums2.size()){
		    path.push_back(nums2[j]);
		    res = max(res, dfs(nums1, nums2, k-1, i, j+1, path));
		    path.pop_back();
		    res = max(res, dfs(nums1, nums2, k, i, j+1, path));
	    }
	    return res;
    }
    vector<int> solve1(vector<int>& nums1, vector<int>& nums2, int k) {
	    vector<int> path;
	    return dfs(nums1, nums2, k, 0, 0, path);
    }
    vector<int> pickMaxSubsequence(vector<int> &nums, int k){
	    int n = nums.size();
	    vector<int> st;
	    int rem = n, l=0, discard=n-k;
	    for(int i = 0 ;i < n; i++){
		    while(!st.empty() && st.back() < nums[i] && discard){
			    st.pop_back();
			    discard--;
		    }
		    st.push_back(nums[i]);
	    }
	    while(st.size() > k)st.pop_back();
	    return st;
    }
    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
	    vector<int> res;
	    int i = 0, j = 0, n = nums1.size(), m = nums2.size();
	    while(i < n || j < m){
		    if(lexicographical_compare(nums1.begin()+i, nums1.end(), nums2.begin()+j, nums2.end())){
			    res.push_back(nums2[j++]);
		    }else res.push_back(nums1[i++]);
	    }
	    return res;
    }
    vector<int> solve2(vector<int>& nums1, vector<int>& nums2, int k) {
	    vector<int> res;
	    int n = nums1.size(), m = nums2.size();
	    for(int i = max(0, k-m); i <= min(n, k); i++){
		    auto sub1 = pickMaxSubsequence(nums1, i);
		    auto sub2 = pickMaxSubsequence(nums2, k-i);
		    auto current = merge(sub1, sub2);
		    res =  max(current, res);
	    }
	    return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	    return solve2(nums1, nums2, k);
    }
    //Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
    //                  i
    //                                    j
    //             9 3 4 6 5
    //Output: [9,8,6,5,3]
};
