/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> solve(vector<vector<Interval> > &schedule){
	    vector<Interval> all;
	    for(auto _intervals:schedule){
		    for(auto _interval:_intervals){
			    all.push_back(_interval);
		    }
	    }
	    sort(all.begin(), all.end(), [](const Interval &a, const Interval &b){
			    return a.start < b.start;
			    });
	    vector<Interval> res;
	    int n = all.size(), _start = all[0].start, last = all[0].end;
	    for(int i = 0; i < n; i++){
		   if(all[i].start >= last){
			   _start = all[i].start;
			   if(last < _start)
			   res.push_back(Interval(last, _start));
		   }
		   last = max(last, all[i].end);
	    }
	    return res;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
	    return solve(schedule);
    }
};
