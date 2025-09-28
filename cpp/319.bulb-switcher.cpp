class Solution {
public:
    int bulbSwitch(int n) {
	    if(n==0)return 0;
	    return sqrt(n);
	    // n   ans
	    // 0   0
	    // 1   1
	    // 2   1
	    // 3   1
	    // 4   2
	    // 5   2
	    //   res = sqrt(n)
	    //    0 0 0
	    // R1 1 1 1 1 1
	    //    1 0 1 0 1
	    //    1 0 0 0 1
	    //    1 0 0 0 1
	    //
    }
};
