class Solution {
public:
	// 0  0  1  0
	// 0  1  1  0
	// ----------
	// 0  1  0  1
	// 
    int minFlips(int a, int b, int c) {
	int both = a|b;
	int zero2one = c&(~both);
	int one2zeroA = (~c)&a;
	int one2zeroB = (~c)&b;
	return __builtin_popcount(zero2one)+__builtin_popcount(one2zeroA)+__builtin_popcount(one2zeroB);
    }
};
