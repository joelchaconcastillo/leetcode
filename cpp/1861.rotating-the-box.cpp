class Solution {
public:
    vector<vector<char>> solve(vector<vector<char>> &grid){
	  int n = grid.size(), m = grid[0].size();
	  for(int i = 0 ; i <n; i++){
	     for(int j = m-1; j>=0; j--){
		     if(grid[i][j]!='.')continue;
		     int k = j;
		     while(k>0 && grid[i][k] == '.') k--;
//		     if(k<0)continue;
		     if(grid[i][k] != '#')continue;
		     swap(grid[i][j], grid[i][k]);
	     }
	  }
	  //transpose
	  vector<vector<char>>res(m, vector<char> (n, '.'));
	  for(int i = 0 ; i < n; i++){
	     for(int j = 0; j < m; j++){
		     res[j][n-i-1] = grid[i][j];
	     }
	  }
	  return res;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
	   return solve(boxGrid);
    }
};
