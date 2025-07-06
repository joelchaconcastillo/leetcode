class Solution {
public:
    string solve(string &st){
	    map<char, int>counter;
	    int n = st.size();
	    for(int i = 0 ; i < n; ){
		    char letter = st[i++];
		    string rep= "";
		    while(i < n && st[i] >= '0' && st[i] <='9'){
			    rep += st[i];
			    i++;
		    }
		    counter[letter]+= stoi(rep);
	    }
	    string res = "";
	    for(auto [letter, cont]:counter){
		    res += letter+to_string(cont);
	    }
	    return res;
    }
    string betterCompression(string compressed) {
	    return solve(compressed);
    }
};
