class Solution {
public:
    int MAXTIME = 24*60;
    int to_seconds(string &time){
	   return stoi(time.substr(0,2))*60+stoi(time.substr(3,2));
    }
    int solve1(vector<string>& timePoints) {
        vector<int> secTimePoints;
        for(auto time:timePoints){
		secTimePoints.push_back(to_seconds(time));
	}	
	sort(secTimePoints.begin(), secTimePoints.end());
	int mindiff=INT_MAX, n = timePoints.size();
	for(int i = 0 ;i<secTimePoints.size(); i++){
		int time1 = secTimePoints[i];
		int time2 = secTimePoints[(i+1)%n];
		int delta = abs(time2-time1);
		mindiff = min(mindiff, delta);
		mindiff = min(mindiff, MAXTIME-delta);
	}
	return mindiff;

    }
    int solve2(vector<string>& timePoints) {
	    vector<bool> min_found(MAXTIME,false);
	    for(auto time:timePoints){
		    auto current_time = to_seconds(time);
		    if(min_found[current_time])return 0;
		    min_found[current_time]=true;
	    }
	    int res = INT_MAX, prevTime = -1, firstOne = -1, lastOne=-1;
	    for(int i = 0 ; i < MAXTIME; i++){
		    if(min_found[i] && prevTime==-1){
			    firstOne=i;
			    prevTime=i;
			    lastOne=i;
		    }else if(min_found[i]){
			    lastOne=i;
			    res = min(res, i-prevTime);
			    prevTime=i;
		    }
	    }
	    return min(res, MAXTIME-(lastOne-firstOne));
    }
    int findMinDifference(vector<string>& timePoints) {
	    return solve2(timePoints);
    }
};
