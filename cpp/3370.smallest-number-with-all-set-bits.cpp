class Solution {
public:
    int solve(int n){
	 int bits = 31-__builtin_clz(n);
	 int mask = (1<<(bits+1))-1;
	 return mask;
    }
    int smallestNumber(int n) {
	    return solve(n);
    }
};
