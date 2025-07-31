class Solution {
public:
    string solve(string &st, string &part){
	    string stack="";
	    int n = st.size(), m = part.size();
	    for(int i = 0 ; i < n ;i++){
		    stack.push_back(st[i]);
		    while( (int)stack.size()-m >=0 &&
				    stack.substr(stack.size()-m, m) == part){ // |stack| =1, |part| = 1, 1-1 = 0

			    for(int i = 0; i < m; i++) stack.pop_back();
		    }
	    }
	    return stack;
    }
    vector<int> KMP(string &st){
	    int n =st.size();
	    vector<int> pref(n, 0);
	    int j = 0;
	    for(int i = 1; i < n; i++){
		    j = pref[i-1];
		    while(j>0 && st[i]!=st[j])// abc abd
			    j = pref[j-1];
		    if(st[i]==st[j]) j++;
		    pref[i]=j;
	    }
	    return pref;
    }
    string solve2(string &st, string &part){
	    int n =st.size(), m = part.size();
	    vector<int> LPS = KMP(part);
	    string stack ="";
	    vector<int> patternIndexes(n+1,0);
	    for(int i = 0, j=0; i<n; i++){
		    stack.push_back(st[i]);
		    if(st[i] == part[j]){
			    patternIndexes[stack.size()] = ++j;
			    if(j == part.size()){
				    int remL = part.size();
				    while(remL){
					    stack.pop_back();
					    remL--;
				    }
				    j = stack.empty()?0:patternIndexes[stack.size()];
			    }
		    }else{
			    if(j!=0){
				    i--;
				    j = LPS[j-1];
				    stack.pop_back();
			    }else{
				    patternIndexes[stack.size()] = 0;
			    }
		    }
	    }
	    return stack;
    }
    string removeOccurrences(string s, string part) {
	    return solve2(s, part);
	    return solve(s, part);
    }
};

//  daabcbaabcbc  part = abc
//  da---ba---bc  part = abc
//  dab  part = abc
//  
//
//  abdabcdabc   abcabc
//  abcabc
//        i
//  aecabcaaabaa    aaab
//     abcabcd
//             
