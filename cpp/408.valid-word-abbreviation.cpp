class Solution {
public:
    bool solve(string &word, string &abbr){
	    int n = abbr.size(), i = 0;
	    string res = "";
	    while(i<n){
		    if(isdigit(abbr[i])){
		      string num="";
		      if(abbr[i]=='0')return false;
		      while(i < n && isdigit(abbr[i])){
			    num +=abbr[i];
			    i++;
		      }
		      if(stoi(num)+res.size() > word.size())return false;
		      res += string(stoi(num),'-');
		    }else{
		      res += abbr[i];
		      i++;
		    }
	    }
	    if(word.size() != res.size())return false;

	    for(int i = 0 ; i < word.size(); i++){
		    if(res[i]=='-')continue;
		    if(word[i]!=res[i]) return false;
	    }
	    return true;
    }
    bool validWordAbbreviation(string word, string abbr) {
	    return solve(word, abbr);
    }
};
