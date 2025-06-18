class Solution {
public:
    int solve(vector<string> &words, string &pref){
	    int res =0 ;
	    for(auto word:words){
		    if(word.size() < pref.size())continue;
		    if(pref == word.substr(0, pref.size()))res++;
	    }
	    return res;
    }
    int prefixCount(vector<string>& words, string pref) {
	    return solve(words,pref);
    }
};
