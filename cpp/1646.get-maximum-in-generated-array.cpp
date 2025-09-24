class Solution {
public:
    int solve1(int n) {

       if(n <=1)return n;
       vector<int> nums(n+1,0); 
       int res = 0;
       nums[0] = 0;
       nums[1] = 1;
       for(int i = 2; i < nums.size(); i++){
	       if(i%2==0) nums[i] = nums[i/2];
	       else nums[i] = nums[i/2]+nums[i/2+1];
	       res = max(res, nums[i]);
       }
       return res;
    }
    int getMaximumGenerated(int n) {
	    return solve1(n);
    }
};
