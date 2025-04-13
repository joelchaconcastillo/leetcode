class Solution {
public:
    int solve(vector<int> &nums){
	int n = nums.size();
	vector<int> _left(n, 0), _right(n, 0);
	int sum = 0;
	for(int i = 0 ;i < n; i++)
		_left[i] = nums[i]+sum, sum+=nums[i];
	sum = 0;
	for(int i = n-1; i>=0; i--) 
		_right[i] = nums[i]+sum, sum+=nums[i];
	for(int i = 0 ;i < n; i++){
		if( _left[i] == _right[i] )return i;
	}
	return -1;
    }
    int pivotIndex(vector<int>& nums) {
	return solve(nums);
    }
};
/*
     - - - - - -  
   x - - - - - - x 
   x - - - - - - x 


 * */
