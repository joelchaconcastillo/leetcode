class Solution {
public:
    int solve(vector<vector<int> > &points2){
	vector<vector<long long> > points;
	for(auto ii:points2) points.push_back({ii[1],ii[0]});
	points.push_back({LONG_MAX, LONG_MAX});
	sort(points.begin(), points.end());
	int n = points.size(), current_left=0, res = 0;
	for(int i = 1; i < n ;i++){
	    if(points[i][1] > points[current_left][0])res++, current_left=i;
	}
	return res;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
	return solve(points);
    }
};
