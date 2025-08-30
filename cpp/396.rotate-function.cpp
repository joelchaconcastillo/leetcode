class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
      //   F(k) = SUM - a[k+n-1]*n - F(k-1) 
	   int SUM = 0, n = nums.size(), Fk1 = 0;
	   for(int i = 0 ;i  < n; i++){
		   FK1 += i*nums[i]
		   SUM += nums[i];
	   }
	   int res = FK1;
	   for(int k = 1; k < n; k++){
		   FK1 =  SUM - a[(n+k)%n]*n - FK1;
		   res = max(res, FK1);
	   }
	   return res;
    }
};
//Input: nums = [4,3,2,6]
//Output: 26
//   4 3 2 6
//   0 1 2 3
//   3 0 1 2
//   2 3 0 1
//   1 2 3 0
//
//   0 1 2 3
//   4 3 2 6 = 25
//   6 4 3 2 = 16
//   2 6 4 3 = 23
//   3 2 6 4 = 26
//
//   \sum a(i)*i -> \sum a(i+1)*i 
//
//   F(0)   = a[0]*0 + a[1]*1 + a[2]*2+ ... + a[n-1]*(n-1) --> 4*0 + 3*1 + ... + 6*3
//   F(1) = a[0]*1 + a[1]*2 + a[2]*3+ ... + a[n-1]*0 --> 4*1 + 3*2 + ... + 6*0
//   F(0) - F(1) = a[0]*(0-1) + a[1]*(2-1) + a[2]*(3-2)+ ... +a[n-1]*(-n+1)
//   F(0) - F(1) = a[0]*1 + a[1]*1 + a[2]*1+...++a[n-1]*(-n+1)
//               =  (\sum_{i=0}^{n-1} a[i]) + a[n-1]*(-n+1) 
//               =    SUM1 -n*a[n-1]+a[n-1]   where SUM1 is not considering last item
//               =    SUM - n*a[n-1]          where SUM is the sum of all items on a
//   F(1) - F(0) = SUM - a[n-1]*n
//   F(1) = -a[0] +SUM - a[n-1]*n - F(0)
//   F(k) = -a[k-1] + SUM - a[k+n-1]*n - F(k-1) 
//
