class Solution {
public:
    /*
       time: O(n*m)
       space: O(1)
       elapsed time to solve: 6 min.
     * */
    bool solve(vector<vector<char>>& grid){
	int n = grid.size(), m = grid[0].size();
	vector<int> rows(10,0), cols(10, 0), blocks(10, 0);
	for(int i = 0 ; i < n; i++){
	    for(int j = 0 ; j < m; j++){
	       if(grid[i][j]=='.')continue;
	       int block = (i/3)*3+(j/3);
	       int val = grid[i][j]-'0';
	       if(rows[i]&(1<<val))return false;
	       if(cols[j]&(1<<val))return false;
	       if(blocks[block]&(1<<val))return false;
	       rows[i] |= (1<<val);
	       cols[j] |= (1<<val);
	       blocks[block] |= (1<<val);
	    }
	}
	return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       return solve(board);
    }
};
