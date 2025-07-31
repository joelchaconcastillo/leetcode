class Solution {
public:
    string solve(vector<vector<string> > &responses){
	    unordered_map<string, int> freq;
	    pair<int, string >largest(1000000, "");
	    for(auto response:responses){
		    unordered_set<string> res;
		    for(auto &ii:response) res.insert(ii);
		    for(auto &ii:res){
			    freq[ii]++;
			    largest = min(largest, {-freq[ii], ii});
		    }
	    }
	    return largest.second;
    }
    string findCommonResponse(vector<vector<string>>& responses) {
	    return solve(responses);
    }
};
