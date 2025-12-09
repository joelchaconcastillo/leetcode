class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
	    unordered_set<char> broken;
	    for(auto letter:brokenLetters)broken.insert(letter);
	    int res = 0;
	    text +=" ";
	    string current = "";
	    bool has_invalid = false;
	    for(auto letter:text){
		    if(letter == ' '){
			    if(!has_invalid) res++;
			    current = "";
			    has_invalid=false;
		    }else current += letter;
		    if(broken.count(letter)) has_invalid=true;
	    }
	    return res;
    }
};
