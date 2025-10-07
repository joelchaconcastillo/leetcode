class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
	for(int i = 0 ;i < n ;i++){
		int maxH = 0;
		for(int j = 0 ; j < m; j++){
			res += grid[i][j]>0;
			maxH = max(maxH, grid[i][j]);
		}
		res += maxH;
	}
	for(int j=0; j < m; j++){
		int maxH =0 ;
		for(int i = 0 ;i  <n ;i++){
			maxH = max(maxH, grid[i][j]);
		}
		res += maxH;
	}
	return res;
    }
};
