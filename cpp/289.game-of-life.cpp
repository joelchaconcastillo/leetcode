class Solution {
public:
    /*
       time: O(n*m)
       space: O(1)
       elapsed time to solve it: 13 min.
     * */
    void solve(vector<vector<int> > & grid){
	 int n = grid.size(), m = grid[0].size();
	 vector<vector<int> > _adj = {
            {-1, -1},{-1, 0},{-1, 1},
	     {0, -1},       {0, 1},
	     {1, -1},{1, 0},{1, 1}
	 };
	 /*
	    0 --> 1: 2
	    1 --> 0: 3
	    0 --> 0: 4
	    1 --> 1: 5
	  * */
	 for(int i = 0; i < n; i++){
	    for(int j = 0 ; j < m; j++){
		int counter = 0;
		for(auto _move:_adj){
		   int to_row = _move[0]+i, to_col = _move[1]+j;
		   if(to_row < 0 || to_row >= n) continue;
		   if(to_col < 0 || to_col >= m) continue;
		   if(grid[to_row][to_col] == 1 || grid[to_row][to_col] == 3 || grid[to_row][to_col] == 5)
		   counter++;
		}
		bool isOn = false;
		if(counter == 2) isOn = grid[i][j];
		else if(counter == 3) isOn = true;
		if(grid[i][j] == 0 && isOn) grid[i][j]=2;
		if(grid[i][j] == 1 && !isOn) grid[i][j]=3;
		if(grid[i][j] == 0 && !isOn) grid[i][j]=4;
		if(grid[i][j] == 1 && isOn) grid[i][j]=5;
	    }
	 }
	 for(auto &i:grid){
		 for(auto &j:i) if(j == 2 || j == 5)j=1; else j=0;
	 }
    }
    void gameOfLife(vector<vector<int>>& board) {
	 solve(board);
    }
};
/*
 
   0 if  sum n(i) < 2 and i == 1
   1 if  sum n(i) ==2 || 3 and i==1
   0 if  sum n(i) >4 i==1
   1 if  sum n(i) == 3 i ==0  
   
 * */
