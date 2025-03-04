class Solution {
public:
    /*
       time: O(n)
       space: O(1)
       time elapsed: 6 min
    */
    vector<int> solve(vector<int> &nums){
       int n = nums.size();
       for(int i = 0 ;i+1 < n; i++){
	  if(nums[i]==nums[i+1])nums[i]*=2, nums[i+1]=0;
       }
       int j = 0;
       for(int i = 0 ; i < n; i++){
	  if(nums[i]==0){
	    j=i+1;
	    while(j<n && nums[j]==0)j++;
	    if(j==n)break;
	    swap(nums[i], nums[j]);
	  }
       }
       return nums;
    }
    vector<int> applyOperations(vector<int>& nums) {
	return solve(nums);
    }
};
/*
  
 [1,2,1,0,0,0]
      i
            j
 * */
