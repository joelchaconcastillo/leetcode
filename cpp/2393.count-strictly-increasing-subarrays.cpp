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
    // 1 3 5 4 4 6
    //       l
    //       i
    // +6
    long long solve2(vector<int> &nums){
	    int n = nums.size(), l = 0,  i =0;
	    long long res = 0;
	    while(i < n){
		    if( i+1<n && nums[i]>= nums[i+1]){
			    long long len = i-l+1;
			    res += len*(len+1LL)/2LL;
			    l=i+1;
		    }
		    i++;
	    }
	    res += (n-l)*(n-l+1LL)/2LL;
	    return res;
    }
    long long solve3(vector<int> &nums){
	    int n = nums.size();
	    long long current_subsarray = 1, subarray_count = 1;
	    for(int i = 1; i < n; i++){
		    if(nums[i] > nums[i-1]){
			    current_subsarray++;
		    }else current_subsarray=1;
		    subarray_count += current_subsarray;
	    }
	    return subarray_count;
    }
    long long countSubarrays(vector<int>& nums) {
	    return solve3(nums);
	    return solve2(nums);
	    return solve(nums);
    }
};
