class Solution {
public:
    int solve(int num1, int num2){
	long long x = num1, sz1 = __builtin_popcount(num1), sz2 = __builtin_popcount(num2);
	int i = 0;
	while(sz1 < sz2 && i < 32){
		if(! (x & (1<<i))){
		   x|=(1<<i);
		   sz1++;
		}
		i++;
	}
	i = 0;
	while(sz1 > sz2 && i < 32){
		if(x&(1LL<<i)){
			x ^= (1LL<<i);
			sz1--;
		}
		i++;
	}
	return static_cast<int>(x);
    }
    int minimizeXor(int num1, int num2) {
	    return solve(num1, num2);
    }
};
