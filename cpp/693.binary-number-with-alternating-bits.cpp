class Solution {
public:
    bool hasAlternatingBits(int n) {
	    bool prev = !(n&1);
	    while(n){
		    bool current = n&1;
		    if(prev == current)return false;
		    prev = current;
		    n>>=1;
	    }
	    return true;
    }
};
