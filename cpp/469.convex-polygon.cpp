class Solution {
public:
    int cross(vector<int> &a, vector<int> &b, vector<int> &c){//check clock-wise or counter-clockwise
	    int dx1 = b[0]-a[0], dy1 = b[1]-a[1];
	    int dx2 = c[0]-b[0], dy2 = c[1]-b[1];
	    return dx1*dy2 - dy1*dx2;
    }
    bool solve(vector<vector<int> > &points){
	    int n = points.size();
	    int direction = cross(points[0], points[1], points[2]);//take the direction of the first three points, it must be the same on all 3-subarrays
	    for(int i = 0 ; i <n; i++){
	        int CP = cross(points[i], points[(i+1)%n], points[(i+2)%n]);
		if(CP == 0) continue;
		if((CP>0) != (direction>0)) return false;
	    }
	    return true;
    }
    bool isConvex(vector<vector<int>>& points) {
	    return solve(points);
    }
};
