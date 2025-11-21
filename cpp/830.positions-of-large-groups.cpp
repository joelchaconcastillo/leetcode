class Solution {
public:
    vector<vector<int>> solve(string s) {
	    vector<vector<int> > res;
	    int n = s.size();
	    char prev = s[0];
	    int prev_start = 0;
	    for(int i = 0 ; i < n; i++){
		    if(s[i]!=prev){
			 int delta = i-prev_start;
			 if(delta>=3){
			     res.push_back({prev_start, i-1});
			 }
		         prev_start = i;
		    }
		    prev = s[i];
	    }
	    if(n-prev_start >=3){
		    res.push_back({prev_start, n-1});
	    }
	    return res;
    }
    vector<vector<int>> largeGroupPositions(string s) {
	    return solve(s);
    }
};
