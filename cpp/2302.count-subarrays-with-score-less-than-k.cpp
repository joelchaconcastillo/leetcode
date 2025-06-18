class Solution {
public:
    long long solve(vector<int> &nums, long long k){
	    int n = nums.size();
	    long long l=0, sum=0;
	    long long res=0;
	    for(long long i = 0 ; i < n; i++){
		sum +=nums[i];
		while( (i-l+1)*(sum) >=k){
			sum -= nums[l];
			l++;
		}
		long long z = (i-l+1);
		res +=z;
	    }
	    return res;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
	    return solve(nums, k);
    }
};
