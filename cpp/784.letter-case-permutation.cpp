class Solution {
public:
    void helper(string &st, string &current, vector<string> &res){
	    if(current.size() ==st.size()){
		    res.push_back(current);
		    return;
	    }
	    int i = current.size();
	    if(isdigit(st[i])){
		    current.push_back(st[i]);
		    helper(st, current, res);
		    current.pop_back();
		    return;
	    }
	    current += st[i];
	    helper(st, current, res); 
	    current.pop_back();

	    current += toupper(st[i]);
	    helper(st, current, res); 
	    current.pop_back();
    }
    vector<string> solve(string &st){
	    for(auto &letter:st){
		    if(isdigit(letter))continue;
		    letter = tolower(letter);
	    }
	    vector<string> res;
	    string current = "";
	    helper(st, current, res);
	    return res;
    }
    vector<string> letterCasePermutation(string s) {
	    return solve(s);
    }
};
