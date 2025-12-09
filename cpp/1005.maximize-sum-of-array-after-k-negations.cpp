class Solution {
public:
    int solve(vector<int>& nums, int k) {
	    sort(nums.begin(), nums.end());
	    int n = nums.size(), i = 0;
	    while(k>0 && i < n && nums[i]<0){// k:3, i=1
		    nums[i]=-nums[i];
		    i++;
		    k--;
	    }
	    k%=2;
	    if(k==0)
	    return accumulate(nums.begin(), nums.end(), 0);
	    int  j = 0;
	    for(int i = 0;i < n; i++){
		    if(abs(nums[j]) > abs(nums[i])){
			    j=i;
		    }
	    }
	    nums[j] = -nums[j];
	    return accumulate(nums.begin(), nums.end(), 0);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
	return solve(nums, k);
    }
};
