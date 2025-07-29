class Solution {
public:
    int solve(vector<int> &nums, int target){
	    sort(nums.begin(), nums.end());
	    int n = nums.size();
	    int res = 0;
	    for(int i = 0; i < n; i++){
		    for(int j = i+1; j < n; j++){
			    int rem = target-nums[i]-nums[j];
			    int idx = lower_bound(nums.begin()+j+1, nums.end(), rem)-nums.begin();
			    if(idx == n)idx--;
			    while(idx>j && nums[idx] >= rem)idx--;
			    res += idx-j;
		    }
	    }
	    return res;
    }
    int two(vector<int> &nums, int start, int target){
	    int n = nums.size();
	    int l = start, r=n-1, res = 0;
	    while(l<r){
		    if(nums[l]+nums[r]>=target)r--;
		    else{
			    res += r-l;
			    l++;
		    }
	    }
	    return res;
    }
    int solve2(vector<int> &nums, int target){
	    sort(nums.begin(), nums.end());
	    int n = nums.size(), res = 0;
	    for(int i = 0 ; i < n; i++){
		    res += two(nums, i+1, target-nums[i]);
	    }
	    return res;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
	    return solve2(nums, target);
	    return solve(nums, target);
    }
};
