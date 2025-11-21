class Solution {
public:
    // k    | res
    // 1      4
    // 2      7
    // ---- 2^1
    //
    // 3      44
    // 4      47
    // 5      74
    // 6      77
    // ---- 2^2
    //
    // 7      444
    // 8      447
    // 9      474*
    // 10     477
    // 11     744
    // 12     747
    // 13     774 <--
    // 14     777
    // ---- 2^3
    //
    // 1000   777747447
    //
    // ##dig --> log(1000)/log(2) --> 9
    // 2^9 = 512
    // |---------| --> has c digits
    //
    //  ____
    //   ||
    //   ||
    //   || <--- x
    //   ||  delta 
    //   || 
    //   || <--- k
    //   ||
    //  ____
    //  c=9
    //  1000-2^9 -1
    //  delta = k-2^c - 1 = 487
    //  we have 487 before k with c digits
    //  k = 10
    //  c = 3
    //  x = 10-7 = 3
    //
    //  477 -> 011
    //         477
    //
    //
    string solve(int k) {
	    long long base = log2(k+1);
	    long long x = k-(1LL<<base)+1;
	    string res = "";
	    while(x){
		  if(x%2==0)res+="4";
		  else res+="7";
		  x/=2;
	    }
	    while(res.size() < base) res+="4";
	    reverse(res.begin(), res.end());
	    return res;
    }
    string kthLuckyNumber(int k) {
	   return solve(k);
    }
};
