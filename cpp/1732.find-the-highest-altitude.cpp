class Solution {
public:
    int solve(std::vector<int> &gain){
	    int res=0, current_sum = 0;
	    for(auto h:gain){
		    current_sum +=h;
		    res = max(res, current_sum);
	    }
	    return res;
    }
    int largestAltitude(vector<int>& gain) {
	    return solve(gain);
    }
};
