class Solution {
public:
    // nums[i]%mod == k and cnt % mod == k
    //    [3,2,4]   m=2, k=1
    //     1 0 0   ---> how many sub arrays are there with sum%m==k
    //    
    //    [3,1,9,6] m = 3, k = 0
    //     1 0 1 1  all sub arrays with sum%m == kc--> number of sub arrays with at most k sum
    //       l
    //       r
    //
    //    1) at most k
    //    2) sliding window
    //    3) hash counting
    long long solve(vector<int> &nums, int modulo, int k){
	    int n = nums.size();
	    for(auto &i:nums) i = (i%modulo)==k;
	    long long sum = 0, res = 0;
	    unordered_map<long long, int> freq;
	    freq[0] = 1;
	    for(int i = 0 ; i < n; i++){
		    sum += nums[i];
		    int current_mod = sum %modulo;
		    int want = (current_mod - k +modulo)%modulo;
		    res += freq[want];
		    freq[current_mod]++;
	    }
	    return res;
    }
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
	    return solve(nums, modulo, k);
    }
};
