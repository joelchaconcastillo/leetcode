class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int n = code.size();	    
       vector<int> res(n, 0);
       if(k==0)return res;
       for(int i = 0 ; i < n; i++){
	       for(int j = 1; j <= abs(k); j++){
		       int _next = (k>0)?((j+i)%n):((i-j+n)%n);
		       res[i]+=code[_next];
	       }
       }
       return res;
    }
};
