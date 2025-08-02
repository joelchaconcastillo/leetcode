class Solution {
public:
    vector<int> solve(vector<int> &nums, int k){
	    unordered_map<int, int> freq;
	    int n=nums.size(), l=0;
	    vector<int>res;
	    for(int i = 0 ;i  <n ;i++){
		    freq[nums[i]]++;
		    if(i-l+1 >= k){
		       res.push_back(static_cast<int>(freq.size()));
		       freq[nums[l]]--;
		       if(freq[nums[l]]==0) freq.erase(nums[l]);
		       l++;
		    }
	    }
	    return res;
    }
    vector<int> distinctNumbers(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
