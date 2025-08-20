class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        vector<int> v1, v2;
	string tmp = "";
        for(auto i:version1){
		if(i=='.'){
		    v1.push_back(stoi(tmp));
		    tmp="";
		}else{
			tmp+=i;
		}
	}	
	if(!tmp.empty()) v1.push_back(stoi(tmp));
	tmp = "";
        for(auto i:version2){
		if(i=='.'){
		    v2.push_back(stoi(tmp));
		    tmp="";
		}else{
			tmp+=i;
		}
	}
	if(!tmp.empty()) v2.push_back(stoi(tmp));
	while(v1.size() < v2.size()) v1.push_back(0);
	while(v1.size() > v2.size()) v2.push_back(0);
	if(v1 < v2) return -1;
	if(v1 > v2) return 1;
	return 0;
    }
};
