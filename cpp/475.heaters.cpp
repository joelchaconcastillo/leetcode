class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
	heaters.push_back(INT_MIN);
	heaters.push_back(INT_MAX);
        sort(heaters.begin(), heaters.end());
	long long max_dist = 0;
        for(auto i:houses){
		int idx = lower_bound(heaters.begin(), heaters.end(), i)-heaters.begin();
		long long min_dist = heaters[idx]-i;
		if(idx > 0){
			min_dist = min(min_dist, (long long)i-heaters[idx-1]);
		}
		max_dist = max(max_dist, min_dist);
	}	
	return max_dist;
    }
};
