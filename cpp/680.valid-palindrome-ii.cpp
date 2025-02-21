class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
	while(i < j) if(s[i++]!=s[j--])return false;
	return true;
    }
    /*
       time: O(n)
       space: O(1)
     * */
    bool solve(string &s){
       int n = s.size(), i = 0, j = n-1, missmatch=0;
       while(i<=j){

	  if(s[i]!=s[j]) return  (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
	  i++, j--;
       }
       return true;
    }
    bool validPalindrome(string s) {
	return solve(s);
    }
};
/*

 * */
