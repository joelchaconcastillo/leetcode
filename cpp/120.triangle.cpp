class Solution {
public:
    int solve(vector<vector<int> > &triangle){
	int n = triangle.size();
	for(int i = 1; i <n ; i++){
	   for(int j = 0; j < triangle[i].size(); j++){
	      int j1 = min(j, (int)triangle[i-1].size()-1);
	      int j2 = max(0, j-1);
	      triangle[i][j] += min(triangle[i-1][j1], triangle[i-1][j2]);
	   }
	}
	return *min_element(triangle.back().begin(), triangle.back().end());
    }
    int minimumTotal(vector<vector<int>>& triangle) {
	return solve(triangle);
    }
};
