class Solution {
public:
    bool condition(vector<int> &nums, int k, int val){
	    int cont = 0, n = nums.size();
	    for(int i = 0 ; i < n ;i++){
		    if(nums[i] <= val)cont++,i++;
	    }
	    return k<= cont;
    }
    int Solve(vector<int> &nums, int k){
	    int lo = *min_element(nums.begin(), nums.end());
	    int hi = *max_element(nums.begin(), nums.end());
	    while(lo < hi){
		    int mid = (lo+hi)/2;
		    if(condition(nums, k, mid)){
			    hi = mid;
		    }else lo = mid+1;
	    }
	    return lo;
    }
    int minCapability(vector<int>& nums, int k) {
	    return Solve(nums, k);
    }
};
