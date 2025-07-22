class Solution {
public:
    string solve(string &st){
	    st+=" ";
	   int n = st.size();
	   string tmp="", word="";
	   for(auto letter:st){
		   if(letter == ' '){
		      if(word.empty())continue;
		      reverse(word.begin(), word.end());
		      tmp+= word+" ";
		      word.clear();
		   }else word+=letter;
	   }
	   tmp.pop_back();
	   reverse(tmp.begin(), tmp.end());
	   return tmp;
    }
    string reverseWords(string s) {
      return solve(s);	    
    }
};
