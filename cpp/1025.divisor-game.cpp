class Solution {
public:
    bool solve(int n){
	    return n%2==0;
	    ///2 win
	    ///3 lose
	    ///4 3 2 1
	    ///5 4 
    }
    bool divisorGame(int n) {
	    return solve(n);
    }
};
