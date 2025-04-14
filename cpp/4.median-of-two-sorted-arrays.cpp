class Solution {
public:
    double solve(vector<int> &nums1, vector<int> &nums2){
	   if (nums1.size() > nums2.size()) swap(nums1, nums2);
	   int n1 = nums1.size(), n2 = nums2.size();
	   int N = n1+n2, lo = 0, hi = n1, median = N/2;
	   int isOdd = (N%2);
	   while(lo <= hi){
		int m1 = (lo+hi)/2, m2 = (median-m1+isOdd);// last one we want the left position in cases where N is odd
		int i1, i2, j1, j2;
		if(m1 == 0) i1 = INT_MIN; else i1 = nums1[m1-1];
		if(m1 == n1) i2 = INT_MAX; else i2 = nums1[m1];

		if(m2 == 0) j1 = INT_MIN; else j1 = nums2[m2-1];
		if(m2 == n2) j2 = INT_MAX; else j2 = nums2[m2];

		if( j1 > i2 ) lo = m1+1; //we can increase it
		else if( i1 > j2) hi = m1-1; // we can decrease it
		else{ // both are kind of mixed --> j1 < i2, i1 < j2, i1 < i2, j1 < j2 ---> 
		    if(isOdd) return max(i1, j1); // solution is the max of both medians
		    else {
			    return (max(i1, j1)+min(i2, j2))/2.0;
		    }
		}
	   }
	   return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	  return solve(nums1, nums2);
    }
};
