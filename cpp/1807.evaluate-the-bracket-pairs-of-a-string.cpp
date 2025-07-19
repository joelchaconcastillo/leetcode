class Solution {
public:
    string solve(string &st, vector<vector<string> > &kn){
	    unordered_map<string, string> _dict;
	    for(auto tt:kn){
		    _dict[tt[0]] = tt[1];
	    }
	    int i = 0, n = st.size();
	    string res = "";
	    while(i < n){
		    if(st[i] == '('){
			    string tmp = "";
			    i++;
			    while(i<n && st[i]!=')') tmp+=st[i++];
			    i++;
			    if(!_dict.count(tmp))res+="?";
			    else res += _dict[tmp];
		    }else{
			    res +=st[i++];
		    }
	    }
	    return res;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
	    return solve(s, knowledge);
    }
};
