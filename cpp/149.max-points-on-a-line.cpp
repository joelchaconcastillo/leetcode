class Solution {
public:
    int solve(vector<vector<int> > &points){
	if(points.empty())return 0;
	int n = points.size(), res=1;
	for(int i = 0 ; i < n; i++){
	   map<tuple<int, int>, int> freq;
	   for(int j = i+1; j < n; j++){
	      int delta_y = (points[i][1]-points[j][1]);
	      int delta_x = (points[i][0]-points[j][0]);
	      int _gcd = __gcd(delta_x, delta_y);
	      delta_x /=_gcd;
	      delta_y /=_gcd;
	      freq[{delta_y, delta_x}]++;
	      res = max(res, freq[{delta_y, delta_x}]+1);
	   }
	}
	return res;
    }
    int maxPoints(vector<vector<int>>& points) {
        return solve(points);	    
    }
};
