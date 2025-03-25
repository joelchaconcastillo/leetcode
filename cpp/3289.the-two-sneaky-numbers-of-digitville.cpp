class Solution {
public:
    vector<int> solve(vector<int> &nums){
	int n = nums.size();
	for(auto &i:nums) i++;
	for(auto &i:nums){
	       	nums[abs(i)-1] = -nums[abs(i)-1];
	}
	vector<int> res;
	for(int i = 0 ; i < n-2; i++){
		if(nums[i] > 0)res.push_back(i);
	}
	return res;
    }
    vector<int> getSneakyNumbers(vector<int>& nums) {
	return solve(nums);
    }
};
//freq hash --> O(n), O(n)
//sort --> O(n log n), O(1)
//mutate nums --> O(n), O(1)
// Input: nums = [0,1,1,0] --> 1 2 2 1
//               
// Output: [0,1]
// 
