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
    string substitute(string &input, unordered_map<string, string> &rawMap){
	    string ans = "";
	    for(int i = 0 ; i < input.size(); i++){
		    auto ch = input[i];
		    if(ch == '%'){
			    ans += rawMap[string(1, input[i+1])];
			    i += 2;
		    }else{
			    ans +=ch;
		    }
	    }
	    return ans;
    }
    string substitueFinalString(string &input, unordered_map<string, string> &rawMap){
	    string ans = "";
	    int n = input.size();
	    for(int i = 0 ; i < n; i++){
		    auto ch = input[i];
		    if(ch == '%'){
			    string resolved = rawMap[string(1, input[i+1])];
			    ans += resolved;
			    i +=3;
		    }
		    if( i < n) ans +="_";
	    }
	    return ans;
    }

    string solve2(vector<vector<string> > &replacements, string &text){
	    unordered_map<string ,string> rawMap;
	    unordered_map<string, vector<string> > adj;
	    unordered_map<string, int> inDegree;
	    for(auto &replacement:replacements){
		    auto key = replacement[0];
		    auto val = replacement[1];
		    rawMap[key] = val;
		    for(int i = 0 ; i < val.size(); i++){//build adjacency list
			    if(val[i]=='%'){
				    i++;
				    auto prerequisite = string(1, val[i]);
				    adj[prerequisite].push_back(key);
				    inDegree[key]++;
				    i++;
			    }
		    }
	    }
	    queue<string> q;
	    for(auto &pair:rawMap){
		    if(inDegree[pair.first] == 0) q.push(pair.first);
	    }
	    while(!q.empty()){
		    auto current = q.front();q.pop();
		    for(auto &_to:adj[current]){
			    inDegree[_to]--;
			    if(inDegree[_to]==0){
				    rawMap[_to] = substitute(rawMap[_to], rawMap);
				    q.push(_to);
			    }
		    }
	    }
	    return substitueFinalString(text, rawMap);
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
	    return solve2(replacements, text);
	    return solve(replacements, text);
    }
};
