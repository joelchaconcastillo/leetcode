class Solution {
public:
    int solve(vector<int>& arr) {
	int lo = 0, hi = arr.size()-1, res = -1;
	while(lo<=hi){
	     int mid = (lo+hi)/2;
	     if(arr[mid] < mid) lo = mid+1;
	     else if(arr[mid]>mid) hi=mid-1;
	     else{
		     res = mid;
		     hi=mid-1;
	     }
	}
	if(res==-1)return -1;
	if(res == arr[res])return res;
	return -1;
    }
    int fixedPoint(vector<int>& arr) {
	return solve(arr);
    }
};
