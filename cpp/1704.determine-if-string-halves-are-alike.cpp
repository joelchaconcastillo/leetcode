class Solution {
public:
    bool halvesAreAlike(string s) {
	    int contleft=0, contright=0;
	    int l = 0, r = s.size()-1;
	    unordered_map<char, int>isVowel = {
		    {'a',1}, {'e',1}, {'i', 1}, {'o',1},{'u',1}
	    };
	    while(l < r){
		    if(isVowel[tolower(s[l++])])contleft++;
		    if(isVowel[tolower(s[r--])])contright++;
	    }
	    return contleft==contright;
    }
};
