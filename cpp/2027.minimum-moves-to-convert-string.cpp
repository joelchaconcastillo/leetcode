class Solution {
public:
    int minimumMoves(string s) {
	int res = 0, n = s.size();
        for(int i = 0 ; i < n ;i++){
	   if(s[i] != 'O'){
		   res++;
		   i+=2;
	   }
	}		
	return res;
    }
};
