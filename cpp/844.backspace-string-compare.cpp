class Solution {
public:
    // time: O(n*k)
    // space: O(1) if considered res O(n)
    // elapsed time to solve it: 3 min.
    string clean_str(string &s){
	  int n = s.size();
	  for(int i = 0; i <n ;i++){
	     if(s[i]=='#'){
		 int j = i;
		 while(j>=0 && (s[j] =='#' || s[j] == '*')) j--;
		 if(j>=0) s[j]='*';
	     }
	  }
	  string res="";
	  for(auto i:s) if(i!='*' && i!='#')res+=i;
	  return res;
    }
    bool solve(string &s, string &t){
	 s = clean_str(s);
	 t = clean_str(t);
	 return s==t;
    }
    bool backspaceCompare(string s, string t) {
	   return solve(s, t);
    }
};
