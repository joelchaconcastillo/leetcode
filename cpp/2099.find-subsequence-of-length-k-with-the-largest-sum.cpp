class Solution {
public:
    struct comp1{
	    bool operator ()(const pair<int, int> &a, const pair<int, int> &b){
		    return a.first > b.first;
	    }
    };	    
    struct comp2{
	    bool operator ()(const pair<int, int> &a, const pair<int, int> &b){
		    return a.second<b.second;
	    }
    };
    vector<int> solve(vector<int> &nums, int k){
	    vector<pair<int, int> > index2num;
	    int n = nums.size();
	    for(int i = 0 ; i < n; i++)index2num.push_back({nums[i], i});
	    sort(index2num.begin(), index2num.end(), comp1{});
	    while(index2num.size() > k) index2num.pop_back();
	    sort(index2num.begin(), index2num.end(), comp2{});
	    vector<int> res;
	    for(auto [val, index]:index2num)res.push_back(val);
	    return res;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
