class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
	int n = nums.size();
	int res = nums[0];
	for(auto num:nums){
		if(abs(res)>abs(num)){
			res = num;
		}else if(abs(res)==abs(num)) res = max(res, num);
	}
	return res;
    }
};
