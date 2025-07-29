class Solution {
public:
    int solve(vector<int> &processorTime, vector<int> &tasks){
	    sort(processorTime.begin(), processorTime.end());
	    sort(tasks.begin(), tasks.end());
	    int i = 0, j = 0, n = processorTime.size(), m = tasks.size();
	    int res = 0;
	    for(int i = 0, j=m-1; i < n; i++, j-=4){
		    res = max(res, processorTime[i]+tasks[j]);
	    }
	    return res;
    }
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
	    return solve(processorTime, tasks);
    }
};
