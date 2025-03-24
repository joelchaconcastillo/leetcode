class Solution {
public:

/*   b = r-r%4+1  -->  4-0+1->5
     a = l+l%4    -->  2+2->4
     a' = a/4=1, b' = b/4 = 1
     b'*(b'+1)/2 - a'*(a'-1)/2 -- middle!!
        1-0 -> 0
     Input: queries = [[1,2],[2,4]]
     Output: 3
    
     time: O(|q|*log_4(r)) 
     space: O(1)
     elapsed time to solve: 60 min.
     */
    long long get_counter(int n){
	    long long log4 = 1 + ((n==0)?0:log2(n)/2);
	    long long sum_groups4 = (log4<=0)?0:(pow(4, log4)-1)/3;
	    return log4*(n+1)-sum_groups4;
    }
    long long solve_math(vector<vector<int> > &q){
        long long res = 0;
	for(auto &qq:q){
	   res += (get_counter(qq[1])-get_counter(qq[0]-1)+1)/2;
	}
        return res;	
    }
    long long _log4(long long n){
	    long long res = 0;
	    while(n/4){
		    n/=4;
		    res++;
	    }
	    return res;
    }
    long long solve(vector<vector<int>> &q){
	 long long res = 0;
	 for(auto &qq:q){
	    long long l = qq[0], r = qq[1], operations=0;
	    while(l<=r){
	       long long log4 = _log4(r);
	       long long pow4 = pow(4LL, log4);
	       pow4 = max(pow4, l);//fix val..
	       operations += (r-pow4+1LL)*(log4+1LL);
	       r = pow4-1LL;
	    }
	    res += (operations+1LL)/2LL;
	 }
	 return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
       //return solve(queries);    
       return solve_math(queries);    
    }
};
/*
 f(a,b) --> floor(a/4), floor(b/4)
 Input: queries = [[1,2],[2,4]]
 Output: 3
 1<=|q|<=10^5
 1<=l<=r<=10^9
     1 2
     
     2 3 4


     4-2+1 = 3 
     2  3  4
     ----  -----  -----  -----
     ceil((r-l+1)/4)
     (18-3+1)/4 --> 16/4 --> 4
     (r/4) - (l/4)

     2,6
     2 3 4 5 6
     --- -----
     b = r-r%4-1 21 - 1 -1 -->19
       a                                       b
     3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
     - ------- --------- ----------- ----------- ----
       |                 10 ope           |
     l%4 + f(.) + r%4

     n*(n+1)/2 z(a,b) --> [a,b] --> b*(b+1)/2 - a*(a+1)/2
     -->  sum_{a/4}^{b/4}
     --------
     a' = 4/4 = 1, b' = 17/4 = 4
     10-0 = 10
     1+2+3+4 -->  10
     right
 * */
