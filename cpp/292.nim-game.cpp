class Solution {
public:
    bool solve(int n){
	    if(n%4==0)return false;
	    return true;
	    // 8--> 
	    //      3, 1 
	    // 1 Y
	    // 2 Y
	    // 3 Y
	    // 4 N
	    // 5 Y
	    // 6 Y 
	    // 7 Y
	    // 8 N
    }
    bool canWinNim(int n) {
	    return solve(n);
    }
};
