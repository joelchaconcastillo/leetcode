class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxFreq=0;
        unordered_map<int, int>freq;
	for(auto num:nums){
		freq[num]++;
		maxFreq = max(maxFreq, freq[num]);
	}
	unordered_map<int, int> first_index, last_index;
	for(int i = 0 ;i < nums.size(); i++){
		if(first_index.count(nums[i])==0){
		  first_index[nums[i]]=i;
		}
		last_index[nums[i]]=i;
	}
	int res = INT_MAX;
	for(int i = 0 ; i < nums.size(); i++){
		if(freq[nums[i]] == maxFreq){
		    res = min(res, last_index[nums[i]] - first_index[nums[i]]+1);
		}
	}
	if(res == INT_MAX)return 0;
	return res;
    }
};
