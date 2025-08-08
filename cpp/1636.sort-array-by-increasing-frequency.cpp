class Solution {
public:
    vector<int> solve(vector<int> &nums){
	    unordered_map<int, int> freq;
	    for(auto i:nums) freq[i]++;
	    vector<tuple<int, int> > res;
	    for(auto i:nums){
		    res.push_back({freq[i], -i});
	    }
	    sort(res.begin(), res.end());
	    vector<int> res2;
	    for(auto [freq, num]:res){
		    res2.push_back(-num);
	    }
	    return res2;
    }
    vector<int> frequencySort(vector<int>& nums) {
	    return solve(nums);
    }
};
