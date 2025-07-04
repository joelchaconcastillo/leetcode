class Solution {
public:
    
    int countBattleships(vector<vector<char>>& board) {
	    int n = board.size(), m = board.front().size();
	    int res = 0;
	    for(int i  = 0 ; i < n; i++){
		    for(int j = 0 ; j <m; j++){
			    if(board[i][j]!='X')continue;
			    res++;
			    int ii = i+1;
			    while(ii<n && board[ii][j] == 'X') board[ii++][j]='.';
			    int jj = j+1;
			    while(jj<m && board[i][jj] == 'X') board[i][jj++]='.';
			    board[i][j]='.';
		    }
	    }
	    return res;
    }
};
