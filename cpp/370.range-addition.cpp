class Solution {
public:
    vector<int> solve(int len, vector<vector<int> > &updates){
	    vector<int> delta(len, 0);
	    for(auto update:updates){
		    int l = update[0], r = update[1], d = update[2];
		    delta[l]+=d;
		    if(r+1<len)
		    delta[r+1]-=d;
	    }
	    for(int i = 1; i < len; i++){
		    delta[i]+=delta[i-1];
	    }
	    return delta;
    }
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
	    return solve(length, updates);
    }
};
