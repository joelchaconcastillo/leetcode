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
    int jump(vector<int>& nums) {
	return solve1(nums);
    }
};

/*
 *
 * 
 *  Input: nums = [2,3,0,1,4]
    Output: 2

*/
