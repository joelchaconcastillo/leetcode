class Solution {
public:
    bool is_winner(vector<string> & board, char t){
	 if(board[0][0] == t && board[1][1] == t && board[2][2] == t)
		 return true;
	 if(board[2][0] == t && board[1][1] == t && board[0][2] == t)
		 return true;
	 for(int i = 0 ;i < 3; i++){
 	     if(board[0][i] == t && board[1][i] == t && board[2][i] == t)
		 return true;
 	     if(board[i][0] == t && board[i][1] == t && board[i][2] == t)
		 return true;
	 }
	 return false;
    }
    string solve(vector<vector<int>> &moves){
	    vector<string> board(3,"   ");
	    for(int i = 0 ; i< moves.size(); i++){
	       if(i%2==0)board[moves[i][0]][moves[i][1]]='X';
	       else board[moves[i][0]][moves[i][1]]='O';
	       if(is_winner(board, 'X'))return "A";
	       else if(is_winner(board, 'O')) return "B";
	    }
	    if(moves.size()<9)return "Pending";
	    return "Draw";
    }
    string tictactoe(vector<vector<int>>& moves) {
	    return solve(moves);
    }
};
