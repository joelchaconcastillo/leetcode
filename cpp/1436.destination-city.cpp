class Solution {
public:
    string solve(vector<vector<string> > &paths){
	    unordered_map<string, int> outDeg;
	    for(auto path:paths) outDeg[path[0]]=0, outDeg[path[1]]=0;
	    for(auto path:paths) outDeg[path[0]]++;
	    for(auto [city, deg]:outDeg){
		    if(deg==0)return city;
	    }
	    return "";
    }
    string destCity(vector<vector<string>>& paths) {
	    return solve(paths);
    }
};
