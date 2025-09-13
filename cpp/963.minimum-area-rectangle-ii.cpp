class Solution {
public:
    double dist(vector<int> &a, vector<int> &b){
	    double res = 0;
	    res = (a[0]-b[0])*(a[0]-b[0]) +  (a[1]-b[1])*(a[1]-b[1]);
	    return res;
    }
    double dot(vector<int> &a, vector<int> &b){
	    return a[0]*b[0]+a[1]*b[1];
    }
    double solve1(vector<vector<int>>& points) {
	    int n = points.size();
	    set<vector<int> > marked(points.begin(), points.end());
	    double res = DBL_MAX;
	    for(int a = 0 ; a < n ;a++){
		    for(int b = 0; b < n ;b++){
			    for(int c = 0; c < n; c++){
					    if(a==b || a==c || b==c)continue;
					    vector<int>ab={points[b][0]-points[a][0], points[b][1]-points[a][1]};
					    vector<int>ca={points[a][0]-points[c][0], points[a][1]-points[c][1]};
					    if(dot(ab, ca)!=0)continue;
					    int x = points[b][0]+points[c][0]-points[a][0];
					    int y = points[b][1]+points[c][1]-points[a][1];
					    if(!marked.count({x,y}))continue;
					    double  dist_ab = dist(points[a], points[b]);
					    double  dist_ac = dist(points[a], points[c]);
					    res = min(res, dist_ab*dist_ac);
			    }
		    }
	    }
	    if(res == DBL_MAX)return 0;
	    return sqrt(res);
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
	    return solve1(points);
    }
};

/// c-b+a-b
