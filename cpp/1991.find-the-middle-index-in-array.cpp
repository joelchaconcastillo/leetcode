class Solution {
public:
    int solve(vector<int> &nums){
	int n = nums.size();
	int _sum=0;
	vector<int> _right(n, 0);
	for(int i = n-1; i>=0; i--){
	       	_right[i] = _sum;
	       	_sum+=nums[i];
	}
	_sum = 0;
	for(int i = 0 ; i < n; i++){
	   if( _right[i] == _sum ) return  i;
	   _sum += nums[i];
	}
	return -1;
    }
    int findMiddleIndex(vector<int>& nums) {
	return solve(nums);
    }
};
