class Solution {
public:
    /*
        time: O(n)
        space: O(1)
     * */
    bool solve(string &s){
	 int n = s.size(), i=0,j=n-1;
	 while(i<j){
	    while(i<j && (!isalpha(s[i]) && !isdigit(s[i])))i++;
	    while(i<j && (!isalpha(s[j]) && !isdigit(s[j])))j--;
	    if(i>=j)return true;
	    if(tolower(s[i])!=tolower(s[j]))return false;
	    i++,j--;
	 }
	 return true;
    }
    bool isPalindrome(string s) {
	 return solve(s);
    }
};
