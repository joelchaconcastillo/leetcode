class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
         int sum = nums.front(), max_sum = nums.front();
	 int n = nums.size();
	 for(int i = 1; i < n; i++){
		 if( nums[i] > nums[i-1]){
			 sum +=nums[i];
		 }else{
			 sum = nums[i];
		 }
		 max_sum = max(max_sum, sum);
	 }
	 return max_sum;
    }
};
