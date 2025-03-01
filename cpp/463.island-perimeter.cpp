class Solution {
public:
    /*
     *  time: O(n*m)
     *  space: O(1)
     *  elapsed time: 3 min
     * */
    int islandPerimeter(vector<vector<int>>& grid) {
	int res = 0, n = grid.size(), m = grid.front().size();
	for(int i = 0 ; i < n; i++){
	   for(int j = 0; j < m; j++){
	      if(grid[i][j]==0)continue;
	      if(i==0 || (i>0 && grid[i-1][j] ==0 )) res++;
	      if(j==0 || (j>0 && grid[i][j-1] ==0 )) res++;
	      if(i==n-1 || (i+1<n && grid[i+1][j] ==0 )) res++;
	      if(j==m-1 || (j+1<m && grid[i][j+1] ==0 )) res++;

	   }
	}
	return res;
    }
};
