class Solution {
public:
    vector<int> solve(vector<int> &nums, int key, int k){
	    vector<int> res, pos;
	    int n = nums.size();
	    for(int i = 0 ; i < nums.size(); i++){
		    if(key == nums[i])pos.push_back(i);
	    }
	    unordered_set<int> marked;
	    for(auto i:pos){
		    for(int j = max(0, i-k); j<= min(n-1, i+k); j++){
			    if(marked.count(j))continue;
			    marked.insert(j);
			    res.push_back(j);
		    }
	    }
	    return res;
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
	    return solve(nums, key, k);
    }
};
