class Solution {
public:
    string solve(string &st, char ch){
	    auto it = st.find(ch);
	    if(it == st.size())return "";
	    reverse(st.begin(), st.begin()+it+1);
	    return st;
    }
    string reversePrefix(string word, char ch) {
	    return solve(word, ch);
    }
};
