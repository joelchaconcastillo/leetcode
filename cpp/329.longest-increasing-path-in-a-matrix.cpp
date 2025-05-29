class Solution {
public:
    vector<tuple<int, int>> directions = {
	{0,-1}, {0,1}, {1,0}, {-1,0}
    };
    int n, m;
    int dp1(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &memo){
	if(memo[i][j] != -1) return memo[i][j];
	int res = 1;
	for(auto [delta_r, delta_c]: directions){
	   int next_r = i + delta_r, next_c = j + delta_c;
	   if(next_r<0 ||next_r>=n || next_c< 0||next_c>=m)continue;
	   if(matrix[i][j] >= matrix[next_r][next_c])continue;
	   res = max(res, dp1(matrix, next_r, next_c, memo)+1);
	}
	return memo[i][j] = res;
    }
    int solve1(vector<vector<int> > &matrix){
	n = matrix.size(), m = matrix[0].size();
	vector<vector<int> > memo(n, vector<int> (m, -1));
	int res = 0;
	for(int i = 0 ; i < n ;i++){
	    for(int j = 0 ; j < m ;j++){
		res = max(res, dp1(matrix, i, j, memo));
	    }
	}
	return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
	return solve1(matrix);
    }
};
