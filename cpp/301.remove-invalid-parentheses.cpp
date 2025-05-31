class Solution {
public:
    int maxSize = 0;
    vector<string> res;
    unordered_set<string> marked;
    void dp(string &s, string &current, int idx, int matching){
	if(matching<0)return;
        if(idx == s.size()){
	   if(matching > 0)return;
	   if(marked.count(current))return;
	   if(current.size() > maxSize){
		maxSize = current.size();
		res.clear();
		marked.clear();
		marked.insert(current);
		res.push_back(current);
	   }else if(current.size() == maxSize){
		res.push_back(current);
		marked.insert(current);
	   }
	   return ;
	}	

        //taking it
        current.push_back(s[idx]);
	int delta = matching;
	if(s[idx]=='(')delta++;
	else if(s[idx]==')')delta--;
	dp(s, current, idx+1, delta);
	current.pop_back();
	dp(s, current, idx+1, matching);
    }
    vector<string> solve(string &s){
	  res.clear();
	  maxSize=0;
	  string current="";
	  dp(s, current, 0, 0);
	  return res;
    }
    vector<string> removeInvalidParentheses(string s) {
	return solve(s);
    }
};
/*
    "(a)())()"
     (a)()x()
 * */
