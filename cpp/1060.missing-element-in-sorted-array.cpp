class Solution {
public:
    int get_missing(vector<int> &nums, int idx){
	    return (nums[idx]-nums.front()+1)-idx-1;
    }
    int missingElement(vector<int>& nums, int k) {
	    int lo = 0, hi = nums.size();
	    while(lo < hi){
		    int mid = (lo+hi)/2;
		    int missing = get_missing(nums, mid);
		    if( missing >= k) hi=mid;
		    else lo = mid+1;

	    }
	    return nums[0]+k+lo-1;
	    return nums[lo-1]+k-get_missing(nums, lo-1);
    }
};
