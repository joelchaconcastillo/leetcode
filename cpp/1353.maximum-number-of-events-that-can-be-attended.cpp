class Solution {
public:
    int solve(vector<vector<int> > &events){
	    sort(events.begin(), events.end());
	    int res = 0, n = events.size();
	    //[[1,4],[4,4],[2,2],[3,4],[1,1]]
	    // [2,2], [3,4], [4,4]
	    // 2,4,
	    int maxDay=0;
	    for(auto day:events) maxDay=max(maxDay, day[1]);
	    priority_queue<int, vector<int>, greater<>>pq;
            for(int i = 0, j = 0; j <=maxDay; j++){
		    while(i<n && events[i][0]<=j){
			    pq.push(events[i][1]);
			    i++;
		    }
		    while(!pq.empty() && pq.top() < j)pq.pop();
		    if(!pq.empty()){
		      pq.pop();
		      res ++;
		    }
	    }	    
	    return res;
    }
    int maxEvents(vector<vector<int>>& events) {
	    return solve(events);
    }
};
