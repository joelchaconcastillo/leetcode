class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int left_index = 0, right_index = 0, n = nums.size();
	for(int i = 0 ; i < n; i++){
		if(nums[i]==1)left_index=i;
		if(nums[i] == n)right_index=i;
	}
	if( left_index < right_index)return left_index+n-1-right_index;
	return left_index+n-right_index-2;
    }
};
