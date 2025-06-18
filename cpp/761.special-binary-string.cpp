class Solution {
public:
    string f(string st){
	    int counter=0, prev=0, n = st.size();
	    vector<string> special_substrings;
	    for(int i = 0; i < n; i++){
		    if(st[i]=='1')counter++;
		    else counter--;
		    if(counter==0){
			    special_substrings.push_back("1"+f(st.substr(prev+1, i-prev-1))+"0");//i=3, prev=1, 1,2,3 ;  3-1
			    prev = i+1;
		    }
	    }
	    sort(special_substrings.begin(), special_substrings.end());
	    reverse(special_substrings.begin(), special_substrings.end());
	    string res = "";
	    for(auto sub:special_substrings)res+=sub;
	    return res;
    }
    string solve(string &st){
	    return f(st);
    }
    string makeLargestSpecial(string s) {
	    return solve(s);
    }
};
