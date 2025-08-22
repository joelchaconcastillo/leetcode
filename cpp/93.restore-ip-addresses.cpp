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
    vector<string> restoreIpAddresses(string s) {
	    for(int i = 0; i <= 255; i++){
		    valid[to_string(i)]=true;
	    }
	    vector<string> res;
	    dfs(s, "", res, 0, 4);
	    return res;
    }
};
