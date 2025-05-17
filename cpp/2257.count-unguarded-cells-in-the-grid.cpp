class Solution {
public:
    #define EMPTY 0
    #define WALL 1
    #define GUARD 2
    #define GUARDED 3
    
    int solve(int m, int n, vector<vector<int> > &guards, vector<vector<int> > &walls){
	vector<vector<int> > grid(m, vector<int> (n, 0));
	for(auto wall:walls) grid[wall[0]][wall[1]]=WALL;
	for(auto guard:guards) grid[guard[0]][guard[1]]=GUARD;
	for(auto guard:guards){
	    int i  = guard[0]+1, j = guard[1];
	    while(i < m && grid[i][j] != WALL && grid[i][j] != GUARD ){
		    grid[i][j] = GUARDED;
		    i++;
	    }
	    i  = guard[0]-1, j = guard[1];
	    while(i >= 0 && grid[i][j] != WALL && grid[i][j] != GUARD ){
		    grid[i][j] = GUARDED;
		    i--;
	    }
	    i  = guard[0], j = guard[1]+1;
	    while(j < n && grid[i][j] != WALL && grid[i][j] != GUARD ){
		    grid[i][j] = GUARDED;
		    j++;
	    }
	    i  = guard[0], j = guard[1]-1;
	    while(j >= 0 && grid[i][j] != WALL && grid[i][j] != GUARD ){
		    grid[i][j] = GUARDED;
		    j--;
	    }
	}
	int res = 0;
	for(int i = 0 ; i < m; i++){
		for(int j = 0 ; j < n; j++){
			if(grid[i][j] == EMPTY)res++;
		}
	}
	return res;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
	return solve(m, n, guards, walls);
    }
};
