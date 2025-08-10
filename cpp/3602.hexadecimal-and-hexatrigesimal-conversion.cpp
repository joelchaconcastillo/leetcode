class Solution {
public:
    string convert(int n, int base){
	    string res = "";
	    while(n){
		    int num = n%base;
		    if(num>9)res= string(1,'A'+num-10)+res;
		    else res= string(1,(char)num+'0')+res;
		    n /=base;
	    }
	    return res;
    }
    string concatHex36(int n) {
	    return convert(n*n, 16)+convert(n*n*n, 36);
    }
};
