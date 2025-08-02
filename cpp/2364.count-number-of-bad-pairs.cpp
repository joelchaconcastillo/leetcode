class Solution {
public:
    long long solve(vector<int> &nums){
	    unordered_map<int, int> freq;
	    long long n = nums.size();
	    for(int i = 0 ; i < n; i++){
		    nums[i] -= i;
	    }
	    for(auto i:nums)freq[i]++;
	    long long counter = 0;
	    for(auto [num, cont]:freq){
		    if(cont>1)counter += (cont*(cont-1LL))/2LL;
	    }
	    return (n*(n-1)/2)-counter;
	    //   [4, 1, 3, 3]
	    //    4  0  1  0   0
    }
    long long countBadPairs(vector<int>& nums) {
	    return solve(nums);
    }
};
