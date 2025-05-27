class Solution {
public:
    int solve1(vector<int> &nums){
	int n = nums.size();
	vector<int> dp(n, 0);
	//nums = [2,3,1,1,4]
	//              1
	//        1 2   3    
	// r=1,A
	int maxv=0, res = 0;
        for(int i=0; i < n; i++){
	   if(nums[i] > maxv){
	      maxv = nums[i];
	      res++;
	   }
	   maxv--;
//	   if(maxv<0)return 0;
	}
	return res;
    }
    //                       i
   //            1 1 1 1
   //            2  1
    //Input: nums = [2,3,1,1,4]
    //
    //     1 2 3
    //     i               
    // max  : 1
    // gas  : 1
    // ways : 1
    //Output: 2
    int solve2(vector<int> &nums){
	if(nums.size()<=1)return 0;
	int current_gas=0, max_gas=0, ways=0;
	for(int i = 0 ; i < nums.size() ; i++){
	    max_gas = max(max_gas, nums[i]);

	    if(current_gas==0 || (i+1==nums.size() && current_gas>0)){
	       current_gas = max_gas;
	       if(i>0) ways++;
	    }
	    current_gas--;
	    max_gas--;

	}
	return ways;
    }
    int jump(vector<int>& nums) {
	return solve2(nums);
	return solve1(nums);
    }
};

/*
 *
 * 
 *  Input: nums = [2,3,0,1,4]
    Output: 2
       2  3  0  1  4

*/

















