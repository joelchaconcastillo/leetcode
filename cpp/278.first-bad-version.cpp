// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long long lo = 1, hi = (1L<<31)-1L;
       while(lo<hi){
	 long long mid = (lo+hi)/2LL;
	 if(isBadVersion(mid)) hi = mid;// lo  - - - mid - - - hi
	 else lo = mid+1;
       }
       return lo;
    }
};
/*
     0 1
     l h

     0 0 0 0 0  1
               lo--------mid --------------hi


 * */
