class Solution {
public:
    int solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    long long res = 0;
	    for(int i = 0 ; i+3 <=n ;i++){// n:4, i=0,1
		    for(int j = 0; j+3<=m; j++){
			    long long sum = 0;
			    for(int ii = i; ii < i+3; ii++){
				    for(int jj = j; jj < j+3; jj++){
					    sum+=grid[ii][jj];
				    }
			    }
			    sum -= (grid[i+1][j]+grid[i+1][j+2]);
			    res = max(res, sum);
		    }
	    }
	    return res;
    }
    int maxSum(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
