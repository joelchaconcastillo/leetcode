class Solution {
public:
// time: O(n)
// space: O(1) if considering new res mem -->  O(n)
// elapsed time to solve: 2 min.
    vector<int> solve(vector<int> &nums){
	   int l = 0, r = nums.size()-1;
	   vector<int> res;
	   while(l <= r){
		if( abs(nums[l]) > abs(nums[r]))
			res.push_back(nums[l]*nums[l++]);
		else res.push_back(nums[r]*nums[r--]);
	   }
	   reverse(res.begin(), res.end());
	   return res;
    }
    vector<int> sortedSquares(vector<int>& nums) {
       return solve(nums);	    
    }
};
