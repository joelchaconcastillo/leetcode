class Solution {
public:
    int countSmallestPairs(vector<int> &nums, int max_dist){
	    int l = 0, n = nums.size();
	    int res = 0;
	    for(int i = 0 ; i <n ;i++){
		    while( l<i && nums[i]-nums[l] > max_dist){
			    l++;
		    }
		    res += i-l;
	    }
	    return res;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
	    int lo = 0, hi = INT_MAX/2;
	    sort(nums.begin(), nums.end());
	    while(lo < hi){
		 int mid = (lo+hi)/2;
		 if( countSmallestPairs(nums, mid) >= k) hi=mid;
		 else lo=mid+1;
	    }
	    return lo;
    }
    //[1,3,1] k 1
    //   1 1 3
    //       i
    //       j
    //   0: 2
    //
    //
    //   1 1 6 k=3
    //     i
    //       j
};
