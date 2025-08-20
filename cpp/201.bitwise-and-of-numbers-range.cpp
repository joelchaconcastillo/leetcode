class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
	    int res = 0, moves=0;
	    while(left !=right){
		    left>>=1;
		    right>>=1;
		    moves++;
	    }
	    return left<<moves;
    }
};
//
//   5  7 
//   0101
//   0111  
//
//
//
//
