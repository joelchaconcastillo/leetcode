class Solution {
public:
    bool solve(string &st){
	 int n = st.size();
	 int mismatch = 0, i=0, j=st.size()-1;
	 while(i<j){
		 mismatch+= st[i++]!=st[j--];
	 }
	 return mismatch <=2;
    }
    bool makePalindrome(string s) {
	    return solve(s);
    }
};
