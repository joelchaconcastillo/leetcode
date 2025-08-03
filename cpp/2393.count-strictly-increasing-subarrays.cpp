class Solution {
public:
    long long solve(vector<int> &nums){
	    int n = nums.size();
	    int l = 0, prev = nums[0]-1;
	    long long res = n;
	    for(int i = 0 ; i < n; i++){
		    if(nums[i] <= prev){
			    int len = i-l;
			    res += len*(len-1LL)/2LL;
			    l=i;
		    }
		    prev = nums[i];
	    }
	    int len = n-l;
	    res += len*(len-1LL)/2LL;
	    return res;
    }
    long long countSubarrays(vector<int>& nums) {
	    return solve(nums);
    }
};
