class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
	    unordered_map<int, int> freq;
	    for(auto &row:nums){
		    for(auto num:row)freq[num]++;
	    }
	    vector<int> res;
	    for(auto [num, rep]:freq){
		    if(rep == nums.size()) res.push_back(num);
	    }
	    sort(res.begin(), res.end());
	    return res;
    }
};
