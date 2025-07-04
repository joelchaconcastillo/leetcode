class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size();
	    unordered_map<int, int> freq;
	    for(auto i:nums)freq[i]++;
	    int res=0;
	    for(auto [num, cont]:freq){
		    if(cont>1)continue;
		    res += num;
	    }
	    return res;
    }
    int sumOfUnique(vector<int>& nums) {
	    return solve(nums);
    }
};
