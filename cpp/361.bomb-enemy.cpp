class Solution {
public:
    int solve(vector<vector<char> > &grid){
	    int n = grid.size(), m =grid.front().size();
	    vector<vector<int> > dpU(n, vector<int>(m, 0));
	    auto dpD = dpU;
	    auto dpL = dpU;
	    auto dpR = dpU;
	    for(int i = 0 ; i < n; i++){
		    int prev = 0;
		    for(int j = 0; j < m; j++){
			    if(grid[i][j] == 'W')prev=0;
			    else prev += (grid[i][j] == 'E');
			    dpL[i][j] = prev;
		    }
		    prev = 0;
		    for(int j = m-1; j >=0; j--){
			    if(grid[i][j] == 'W') prev = 0;
			    else prev += (grid[i][j]=='E');
			    dpR[i][j] = prev;
		    }
	    }
	    for(int j = 0; j < m; j++){
		    int prev = 0;
		    for(int i = 0 ;i  < n; i++){
			    if(grid[i][j] == 'W')prev =0;
			    else prev += (grid[i][j]=='E');
			    dpU[i][j] = prev;
		    }
		    prev = 0;
		    for(int i = n-1;i  >=0 ; i--){
			    if(grid[i][j] == 'W')prev =0;
			    else prev += (grid[i][j]=='E');
			    dpD[i][j] = prev;
		    }
	    }

	    int res = 0;
	    for(int i = 0; i < n; i++){
		    for(int j = 0 ; j < m; j++){
			    if(grid[i][j] != '0')continue;
			    int current = 0 ;
			    if(i>0)
			    current += dpU[i-1][j];
			    if(i+1<n)
			    current += dpD[i+1][j];
			    if(j>0)
			    current += dpL[i][j-1];
			    if(j+1<m)
			    current += dpR[i][j+1];
			    res = max(res, current);
		    }
	    }
	    return res;
    }
    int maxKilledEnemies(vector<vector<char>>& grid) {
	    return solve(grid);
    }
};
