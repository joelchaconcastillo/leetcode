class Solution {
public:
    unordered_map<string, bool>valid;
    void dfs(string &st, string current, vector<string> &res, int i, int remDots){
	    if(remDots<0)return;
	    if(st.size() == i){
		    if(remDots!=0)return;
		    current.pop_back();//remove extra dot
		    res.push_back(current);
		    return;
	    }
	    string tmp="";
	    for(int j = i; j < st.size(); j++){
		    tmp+=st[j];
		    if(!valid[tmp])break;
		    dfs(st, current+tmp+".", res, j+1, remDots-1);
	    }
    }
    vector<string> solve(string s) {
	    for(int i = 0; i <= 255; i++){
		    valid[to_string(i)]=true;
	    }
	    vector<string> res;
	    dfs(s, "", res, 0, 4);
	    return res;
    }






    vector<string> solve2(string &s) {
	  vector<string> res;
	  for(int i = 0; i <=255; i++){
	    for(int j = 0; j <=255; j++){
	       for(int k = 0; k <=255; k++){
	          for(int l = 0; l <=255; l++){
			  if(to_string(i)+to_string(j)+to_string(k)+to_string(l) !=s)continue;
			  res.push_back(to_string(i)+"."+to_string(j)+"."+to_string(k)+"."+to_string(l));
		  }
	       }
	    }
	  }
	  return res;
    }
    void helper(string &s, vector<string> &res, int i, int dots, string current){
	    if(dots <0 )return;
	    if(i==s.size()){
		    if(dots>0)return;
		    current.pop_back();
		    res.push_back(current);
		    return;
	    }
	    string word="";
	    for(int j = i ; j < s.size(); j++){
		    word += s[j];
		    if(word.size()>1 && word[0]=='0')break;
		    if(stol(word)>255)break;
		    helper(s, res, j+1, dots-1, current+word+".");
	    }
    }
    vector<string> solve3(string s) {
	  vector<string> res;
	  string current = "";
	  helper(s, res, 0, 4, current);
	  return res;
    }
    void helper2(string &s, vector<string> &res, int i, int dots, string current, string last){
	    if(dots<=0)return;
	    if(!last.empty() && stoi(last)>255) return;
	    if(last.size()>1 && last[0]=='0')return;
	    if(i==s.size()){
		if(dots!=1)return;
		res.push_back(current);
	        return;
	    }
	    helper2(s, res, i+1, dots, current+s[i], last+s[i]);
	    if(!current.empty() && current.back()!='.')
	    helper2(s, res, i, dots-1, current+".", "");
    }
    vector<string> solve4(string s) {
	  vector<string> res;
	  helper2(s, res, 0, 4, "", "");
	  return res;
    }
    vector<string> restoreIpAddresses(string s) {
	    return solve4(s);
	    return solve3(s);
    }
};

























