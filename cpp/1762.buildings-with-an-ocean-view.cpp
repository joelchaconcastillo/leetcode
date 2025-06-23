class Solution {
public:
    vector<int> solve(vector<int> &h){
	    int n = h.size();
	    int maxv = INT_MIN;
	    vector<int> res;
	    for(int i = n-1; i >=0 ; i--){
		    if(h[i] > maxv){
			    res.push_back(i);
			    maxv=h[i];
		    }

	    }
	    reverse(res.begin(), res.end());
	    return res;
    }
    vector<int> findBuildings(vector<int>& heights) {
	    return solve(heights);
    }
};
