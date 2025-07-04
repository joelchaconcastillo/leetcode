class Solution {
public:
    string dfs(unordered_map<string, string> &replacements, string current){
	    string changed ="";
	    int n = current.size();
	    for(int i = 0 ; i < n; i++){
		    if(current[i] == '%'){
		       string _key="";
		       while(current[++i]!='%')	  _key +=current[i];
		       changed+=replacements[_key];
		    }else{
			    changed+=current[i];
		    }
	    }
	    if(changed==current)return current;
	    return dfs(replacements, changed);
    }
    string solve(vector<vector<string> > &replacements, string &text){
	    unordered_map<string, string> replacements_map;
	    for(auto _data:replacements){
		    replacements_map[_data[0]] = _data[1];
	    }
	    return dfs(replacements_map, text);
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
	    return solve(replacements, text);
    }
};
