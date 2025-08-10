class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
	    int n = timeSeries.size();
	    int total = 0, max_end = timeSeries[0];
	    for(int i = 0; i  <n; i++){
		    int start = max(max_end, timeSeries[i]);
		    int current_end = timeSeries[i]+duration;
		    total += current_end-start;
		    max_end = max(max_end, current_end);
	    }
	    return total;
    }
};
/*
                E
  s        e 
  |--------|
        |-------|
	     |--------|

 * */
