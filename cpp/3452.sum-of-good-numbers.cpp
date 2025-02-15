class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
	for(int i = 0 ; i <n ; i++){
	   bool cond1 = ( i-k<0 || (i-k>=0 && nums[i-k]<nums[i]));
	   bool cond2 = ( i+k>=n || (i+k<n && nums[i+k]<nums[i]));
	   if(cond1 && cond2) res+=nums[i];
	}
        return res;	
    }
};
