class Solution {
public:
    unordered_map<int, vector<int> > nums_dict;
    Solution(vector<int>& nums) {        
       int n = nums.size();
       for(int i = 0 ;i < n; i++){
	   nums_dict[nums[i]].push_back(i);
       }
    }
    
    int pick(int target) {
	auto &vec = this->nums_dict[target];
	int n = vec.size();
	return vec[(rand()%n)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
