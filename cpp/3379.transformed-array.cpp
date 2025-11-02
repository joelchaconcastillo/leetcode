class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
	   int n = nums.size();
	   vector<int> result(n); 
	   for(int i = 0; i < n; i++){
		   result[i] = nums[(i+nums[i]+100*n)%n];
	   }
	   return result;
    }
};
