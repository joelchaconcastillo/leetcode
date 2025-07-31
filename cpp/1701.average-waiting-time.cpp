class Solution {
public:
    double solve(vector<vector<int> > &customers){
	    double res = 0.0;
	    int n = customers.size();
	    int last = customers[0][0];
	    //[1,2],[2,5],[4,3]
	    // 1 3   3 8   8 11
	    for(int i = 0 ; i < n; i++){
		    int start = max(customers[i][0], last);
		    int end = start+customers[i][1];
		    res += end-customers[i][0];
		    last = end;
	    }
	    return res/n;
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
	    return solve(customers);
    }
};
