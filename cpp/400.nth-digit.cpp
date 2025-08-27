class Solution {
public:
/*
      1-9       9x1
      10-99     90x2
      100-999   900x3
 * */
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // sum = 0, base=1, start=1
    // input: any integer number 
    // output: the sum of digits until this number
    long long th_sequnce(long long th){
         long long sum_digits=0, base=1, len=1;
	 while(base*10 <= th){
		 sum_digits += base*9*len;//TODO check this one!
		 base *=10;
		 len++;
	 }
	 return sum_digits + (th-base+1LL)*len;
    }
    int findNthDigit(int n) {
	    long long lo = 1, hi = 1LL<<31;
	    while(lo < hi){
		    long long mid = (lo+hi)/2;
		    if(th_sequnce(mid)>=n)
			 hi=mid;
		    else lo=mid+1;
	    }
	    long long sum = th_sequnce(lo);
	    while(sum > n){
		    sum--;
		    lo/=10;
	    }
	    return lo%10;
    }
};

