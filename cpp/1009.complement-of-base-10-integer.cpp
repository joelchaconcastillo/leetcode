class Solution {
public:
    int solve(int n){
	    if(n==0)return 1;
	    int msb_pos = 31 -  __builtin_clz(n);
	    int mask = (1<<(msb_pos+1))-1;
	    return n ^ mask;
    }
    int bitwiseComplement(int n) {
	    return solve(n);
    }
};
