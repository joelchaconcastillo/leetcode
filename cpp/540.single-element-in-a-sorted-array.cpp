class Solution {
public:
    // Input: nums = [1,1,2,3,3,4,4,8,8]
    //                l
    //                                r
    //                        m        
    // if a[m] is single: return it
    // if a[m] is not single but its major index is even then move to right
    // else move to left 
    // Output: 2
    pair<int, int> get_max_idx(vector<int> &nums, int idx){
	    if( idx > 0 && nums[idx-1] == nums[idx])return {idx-1, idx};
	    if( idx+1 < nums.size() && nums[idx] == nums[idx+1]) return {idx, idx+1};
	    return {idx, idx};
    }
    int solve(vector<int>& nums) {
	int l = 0, r = nums.size()-1;
	while(l<r){
	     int mid = (l+r)/2;
	     if(mid%2==1)mid--;
	     if(nums[mid] == nums[mid+1]) l = mid+2;
	     else r = mid;
//	     pair<int, int> idxs = get_max_idx(nums, mid);
//	     if(idxs.first == idxs.second){
//		     return nums[idxs.first];
//	     }else if(max(idxs.first, idxs.second)%2==1){
//		    l= mid+1;
//	     }else r = mid-1;
	}
	return nums[l];
    }
    int singleNonDuplicate(vector<int>& nums) {
	return solve(nums);
    }
};
