class Solution {
public:
    void reverseWords(vector<char>& s) {
         int n = s.size();	    
	 int l = 0;
	 for(int i = 0 ; i < n; i++){
		 if(s[i]==' '){
			reverse(s.begin()+l, s.begin()+i);
			l=i+1;
		 }
	 }
	reverse(s.begin()+l, s.end());
	 reverse(s.begin(), s.end());
    }
};
