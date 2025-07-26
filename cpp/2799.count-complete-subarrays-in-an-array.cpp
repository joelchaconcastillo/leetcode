class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size();
	    int l = 0, res=0;
	    unordered_set<int> uniq;
	    for(auto num:nums)uniq.insert(num);
	    unordered_map<int, int> freq;
	    int k = uniq.size();
	    for(int i = 0 ; i < n; i++){
		    freq[nums[i]]++;
		    while(l<=i && freq.size() >= k){
			    freq[nums[l]]--;
			    if(freq[nums[l]]==0) freq.erase(nums[l]);
			    res += n-i;
			    l++;
		    }
	    }
	    return res;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        return solve(nums);
    }
};
