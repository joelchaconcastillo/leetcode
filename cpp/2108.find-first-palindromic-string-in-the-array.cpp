class Solution {
public:
    bool isPalindrome(string &word){
	    int l = 0, r = word.size()-1;
	    while(l < r){
		    if(word[l++]!=word[r--])return false;
	    }
	    return true;
    }
    string solve(vector<string> &words){
	    for(auto word:words){
		    if(isPalindrome(word))return word;
	    }
	    return "";
    }
    string firstPalindrome(vector<string>& words) {
	    return solve(words);
    }
};
