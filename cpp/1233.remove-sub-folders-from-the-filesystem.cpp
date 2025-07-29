class Solution {
public:
    vector<string> solve(vector<string> &folder){
	    int n = folder.size();
	    unordered_set<string> marked;
	    for(auto &path:folder){
		    marked.insert(path+"/");
	    }
	    vector<string> res;
	    for(auto &path:folder){
		    string current = "";
		    bool ignorePath = false;
		    for(auto letter:path){
			    current +=letter;
			    if(current != path && marked.count(current)){
				    ignorePath=true;
				    break;
			    }
		    }
		    if(!ignorePath)res.push_back(path);
	    }
	    return res;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
	    return solve(folder);
    }
};
