class Solution {
public:
    bool solve(vector<vector<int> > &intervals){
	    int n = intervals.size();
	    sort(intervals.begin(), intervals.end());
	    int last = -1;
	    for(int i = 0; i < n; i++){
		    if(intervals[i][0] < last) return false;
		    last = max(last, intervals[i][1]);
	    }
	    return true;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        return solve(intervals);	    
    }
};
