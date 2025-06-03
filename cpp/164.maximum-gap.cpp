class Solution {
public:
    void counting_sort(vector<int> &nums, long long pow){
	 int maxf = 11;
	 vector<int> freq(maxf,0);
	 for(auto i:nums){
	    int idx = (i/pow)%10;// 1234  pow=10
	    freq[idx]++;
	 }
	 for(int i = 1 ; i < maxf; i++){
	    freq[i] +=freq[i-1];
	 }
	 vector<int>tmp=nums;
	 int n = nums.size();
	 for(int i = n-1; i>=0; i--){
	      int idx = (nums[i]/pow)%10;// 1234  pow=10
	      tmp[--freq[idx]] = nums[i];
	 }
	 nums = tmp;
    }
    void radix_sort(vector<int> &nums){
	 long long pow = 1;
	 while(pow < 1e10){
              counting_sort(nums, pow);		 
	      pow *=10;
	 }
    }
    int solve(vector<int> &nums){
	int n = nums.size();
	radix_sort(nums);
	int res = 0;
	for(int i = 0 ; i+1 < n; i++){
	   res = max(res, nums[i+1]-nums[i]);
	}
	return res;
    }
    int maximumGap(vector<int>& nums) {
	return solve(nums);
    }
};
