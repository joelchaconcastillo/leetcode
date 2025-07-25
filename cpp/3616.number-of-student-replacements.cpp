class Solution {
public:
    int solve(vector<int> &r){
	    int n = r.size(), res=0, curren_min = r.front();
	    for(int i =0; i < n ; i++){
		    if(r[i] < curren_min){
			    curren_min = r[i];
			    res++;
		    }
	    }
	    return res;
    }
    int totalReplacements(vector<int>& ranks) {
       return solve(ranks); 
    }
};
