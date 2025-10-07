class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size(), idx=INT_MAX;
        for(int i = 0 ; i <n; i++){
		if(nums[i]==target && abs(start-i) < abs(start-idx))idx=i;
	}	
	return abs(start-idx);
    }
};
