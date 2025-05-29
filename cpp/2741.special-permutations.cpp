class Solution {
public:
    int dp(vector<int> &nums, int idx){



	int res = INT_MAX;
	for(int i = idx; i < n; i++){
	   for(int j = i+1; j < n; j++){
	      
	      res = min(res, dp(nums, 
	   }
	}
	return res;
    }
    int solve(vector<int> &nums){
	int n = nums.size();
    }
    int specialPerm(vector<int>& nums) {
	return solve(nums);
    }
};
