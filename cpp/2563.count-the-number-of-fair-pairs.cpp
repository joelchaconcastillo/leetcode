class Solution {
public:
    long long solve(vector<int> &nums, int lo, int hi){
	    sort(nums.begin(), nums.end());
	    long long res = 0;
	    int n = nums.size();
	    for(int i = 0 ; i < n; i++){
		    int idx1 = lower_bound(nums.begin()+i+1, nums.end(), lo-nums[i])-nums.begin();
		    int idx2 = upper_bound(nums.begin()+i+1, nums.end(), hi-nums[i])-nums.begin();
		    res += (idx2-idx1);
	    }
	    return res;
    }
    long long seek(vector<int> &nums, int val){
	    long long l = 0, r = nums.size()-1, res=0;
	    while(l<r){
		    if(nums[l]+nums[r] >= val) r--;
		    else{
			    res+= static_cast<long long>(r-l);
			    l++;
		    }
	    }
	    return res;
    }
    long long solve2(vector<int> &nums, int lo, int hi){
	    sort(nums.begin(), nums.end());
	    return seek(nums, hi+1)-seek(nums, lo);
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
	    return solve2(nums, lower, upper);
	    return solve(nums, lower, upper);
    }
};
