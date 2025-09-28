class Solution {
public:
    int dist(vector<int> &A, vector<int> &B){
	    return (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
	int res = 0;
        for(int i = 0 ;i < n ; i++){
	unordered_map<int, int> freq;
		for(int j = 0; j < n ; j++){
			if(i==j)continue;
			freq[dist(points[i], points[j])]++;
		}
	for(auto [dif, cont]:freq) res += cont*(cont-1);
	}	
	return res;
    }
};

//[[0,0],[1,0],[2,0]]
//   0     1     2
//   0-1 1
//   0-2 1
//   1-0 1
//   2-1 1
//   1-2 1
//   2-1 1
//
