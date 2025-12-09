class Solution {
public:
    int solve(vector<int>& nums, int k) {
	//Input: nums = [10,5,2,6], k = 100
	//Output: 8
	//   10 5 2 6  ----- k = 100
	//      l
	//          i
	//   prod: 60
	//   ans: 1+2+2+3
	int l = 0, res=0, prod=1, n = nums.size();
	for(int i = 0 ;i  <n; i++){
	    prod *=nums[i];
	    while(l<=i && prod >= k){
		    prod/=nums[l];
		    l++;
	    }
	    res += i-l+1;
	}
	return res;
    }
    int solve2(vector<int>& nums, int k) {
	int n = nums.size();
	vector<double> prefix(n+1,0.0);
	for(int i = 1;i <=n ; i++){
		prefix[i] = prefix[i-1]+log(nums[i-1]);
	}
	int res = 0;
	double logk = log(k);
	for(int i = 0 ; i < n ; i++){
		int lo = i, hi = n;
		while(lo<hi){
		     int mid = (lo+hi)/2;
		     double sum = prefix[mid+1]-prefix[i];// p[mid]-p[i-1]
		     if( sum >= logk-1e-9 ){
			     hi = mid;
		     }else{
			     lo = mid+1;
		     }
		}
		// 0 1 2 
		//   i   
		//       l
		int delta = lo-i;
		res += delta;
	}
	return res;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	    return solve2(nums, k);
	    return solve(nums, k);
    }
};
