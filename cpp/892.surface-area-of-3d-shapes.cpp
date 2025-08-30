class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
	    int n = grid.size(), m = grid[0].size();
	    int bottom = n*m;
	    int top = n*m;
	    int right=0, down=0, middle=0, corners = 0, zeros=0;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0; j < m ;j++){
			    if(j+1<m)right += abs(grid[i][j]-grid[i][j+1]);
			    if(i+1<n) down += abs(grid[i][j]-grid[i+1][j]);
			    zeros += grid[i][j]==0;
		    }
	    }
	    for(int i = 1; i+1 < n; i++) middle += grid[i][0]+grid[i][m-1];
	    for(int j = 1; j+1 < m; j++) middle += grid[0][j]+grid[n-1][j];

	    if(n>1 && m>1)corners = 2*(grid[0][0]+grid[n-1][m-1]+grid[n-1][0]+grid[0][m-1]);
	    else if(n==1 && m==1)corners = 2*(grid[0][0]+grid[n-1][m-1]);
	    else if(n==1 && m>1) corners = 3*grid[0][0]+3*grid[n-1][m-1];
	    else if(n > 1 && m==1) corners = 3*grid[0][0]+3*grid[n-1][m-1];
	    return bottom+
		    top+
		    right+
		    down+
		    corners+
		    middle-2*zeros;
    }
};
//   ans: 34
//   1  2
//   3  4
//
//  bottom: 4
//  top: 4
//  right: abs(i-j) :  +1+1 --> 2
//  bottom: abs(i-j): +2+2  --> 4
//  contour: 2*corner(i)+inter(i): 2+4+8+6-->20
//  34
//   
//
//  
