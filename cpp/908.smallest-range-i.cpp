class Solution {
public:
    // nums = [0,10], k = 2
    //        -2  8
    //         0  10
    //         2  12
    //
    //
    // nums = [1,3,6], k = 3
    //         -2 0 3
    //         1  3  6
    //         4  6  9
    //        [-2,4] - [3, 9]
    //             
    //
    //         1 1 1 1 1 9 9 9 9 9 9   k = 1
    //         2 2               8 8
    //
    //         1 1 1 1 1  k = 1
    //
    //
    int smallestRangeI(vector<int>& nums, int k) {
	    int minv = INT_MAX, maxv = INT_MIN;
	    for(auto num:nums){
		    minv = min(minv, num);
		    maxv = max(maxv, num);
	    }
	    vector<vector<int> > ranges = {
		   {minv-k, minv+k},
		   {maxv-k, maxv+k}
	    };
	    sort(ranges.begin(), ranges.end());
	    return max(0,ranges[1][0] - ranges[0][1]);
    }
};
//
//
//- - 
//
//    - - 
//        - - - 
//
//
///- - 
//
//    - - 
//        - - - 
//
//
//
