class Solution {
public:
    bool eval(vector<long long> nums, long long val){
	int n = nums.size();
	long long rem = 0;
	for(int i = n-1; i>=1; i--){
	   if(nums[i] > val){
	        long long delta = nums[i]-val;
		nums[i] -=delta;
		nums[i-1]+=delta;
	   }
	}
	return nums[0] <= val;
    }
    int solve1(vector<int> &nums2){
	vector<long long>nums;
	for(auto i:nums2)nums.push_back(i);
	int n = nums.size();
	long long lo = 0, hi = *max_element(nums.begin(), nums.end());
	while(lo < hi){
	    long long m = (lo+hi)/2;
	    if(eval(nums, m)){
		 hi=m;
	    }else lo = m+1;
	}
	return lo;
    }
    int solve2(vector<int> nums){
	long long sum = 0, res = 0;
	int n = nums.size();
	for(int i = 0 ;i < n; i++){
	   sum +=nums[i];
	   //res = max(res, (sum+i)/(i+1));
	   res = max(res, (long long) ceil((double)sum / (i + 1)));

	}
	return res;
    }
    int minimizeArrayValue(vector<int>& nums) {
	return solve2(nums);
	return solve1(nums);
    }
};
