class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size();
	    unordered_map<int, int>freq;
	    for(auto i:nums)freq[i]++;
	    int op = 0;
	    for(int i = 0, rem=n; i <n; i+=3, op++){
		    if(freq.size() == rem)return op;
		    for(int j = 0; j < 3 && i+j < n; j++){
			 freq[nums[i+j]]--;
			 if(freq[nums[i+j]]==0) freq.erase(nums[i+j]);
			 rem--;
		    }
	    }
	    return op;
    }
    int minimumOperations(vector<int>& nums) {
	    return solve(nums);
    }
};
