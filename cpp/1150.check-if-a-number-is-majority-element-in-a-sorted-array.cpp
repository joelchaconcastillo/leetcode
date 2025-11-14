class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
         int count = 0;
         for(auto num:nums) count += num==target;
         int n = nums.size();
	 return n/2<count;
    }
};
