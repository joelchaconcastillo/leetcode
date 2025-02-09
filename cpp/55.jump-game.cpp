class Solution {
public:
    /*
        time: O(n)
        space: O(1)
     * */
    bool solve(vector<int> &nums){
	    int n = nums.size();
	    if(n<=1)return true;
	    int maxv = 0;
	    for(int i = 0 ; i+1 < n; i++){
	       maxv = max(maxv-1, nums[i]);
	       if(maxv==0)return false;
	    }
	    return true;
    }
    bool canJump(vector<int>& nums) {
	 return solve(nums);
    }
};
/*
 *
   max: 1
            x
      2 3 1 1 4

   max: 1
          x
      3 2 1 0 4

 * */
