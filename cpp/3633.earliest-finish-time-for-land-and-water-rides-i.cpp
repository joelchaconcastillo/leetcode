class Solution {
public:
    int helper(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
	    int n = landStartTime.size(), m = waterStartTime.size();
	    int res = INT_MAX;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m; j++){
			    int lastTime1 = landStartTime[i]+landDuration[i];
			    int startTime2 = max(lastTime1, waterStartTime[j]);
			    res = min(res, startTime2+waterDuration[j]);
			    int lastTime2 = waterStartTime[j]+waterDuration[j];
			    int startTime1 = max(lastTime2, landStartTime[i]);
			    res = min(res, startTime1+landDuration[i]);
		    }
	    }
	    return res;
    }
    int solve2(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
	    int n = landStartTime.size(), m = waterStartTime.size();
	    int minEndLand = INT_MAX, minEndWater = INT_MAX;
	    for(int i = 0 ;i < n ;i ++){
		    minEndLand = min(minEndLand, landStartTime[i]+landDuration[i]);
	    }
	    for(int i = 0 ;i < m; i++){
		    minEndWater = min(minEndWater, waterStartTime[i]+waterDuration[i]);
	    }
	    int landWater = INT_MAX, waterLand = INT_MAX;
	    for(int i = 0 ; i < m; i++){
		    landWater = min( landWater, max(minEndLand, waterStartTime[i])+waterDuration[i]);
	    }
	    for(int i = 0 ;i < n; i++){
		    waterLand = min(waterLand , max(minEndWater, landStartTime[i])+landDuration[i]);
	    }
	    return min(landWater, waterLand);
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
			    return solve2(landStartTime, landDuration, waterStartTime, waterDuration);
			    return helper(landStartTime, landDuration, waterStartTime, waterDuration);
    }
};
