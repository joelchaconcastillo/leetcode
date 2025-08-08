class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int> &start, vector<int> &end, vector<int> &profit, int i){
	    if(i==start.size())return 0;
	    if(memo.count(i))return memo[i];
	    int res = dfs(start, end, profit, i+1);
	    int j = lower_bound(start.begin(), start.end(), end[i])-start.begin();
	    res = max(res, dfs(start, end, profit, j)+profit[i]);
	    return memo[i] = res;
    }
    int solve(vector<int> &startTime, vector<int> &endTime, vector<int> &profit){
	    vector<tuple<int, int, int> > jobs;
	    int n =startTime.size();
	    for(int i = 0 ;i  < n; i++){
		    jobs.push_back({startTime[i], endTime[i], profit[i]});
	    }
	    sort(jobs.begin(), jobs.end());
	    for(int i = 0; i < n; i++){
		    auto [start, end, _profit] = jobs[i];
		    startTime[i] = start;
		    endTime[i] = end;
		    profit[i] = _profit;
	    }
	    return dfs(startTime, endTime, profit, 0);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	    return solve(startTime, endTime, profit);
    }
};
