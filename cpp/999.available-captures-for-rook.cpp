class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Rock_row=0, Rock_col=0, n=board.size(), m=board[0].size();
        for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < m ;j++){
			if(board[i][j]=='R'){
				Rock_row=i;
				Rock_col=j;
				break;
			}
		}
	}	
	int res = 0;
	int i=Rock_row+1,j=0;
	while(i<n){
		if(board[i][Rock_col]=='p'){
			res++;
			break;
		}else if(board[i][Rock_col]=='B' || board[i][Rock_col] =='R')break;
		i++;
	}
	i=Rock_row-1;
	while(i>=0){
		if(board[i][Rock_col]=='p'){
			res++;
			break;
		}else if(board[i][Rock_col]=='B' || board[i][Rock_col] =='R')break;
		i--;
	}
	j=Rock_col+1;
	while(j < m){
		if(board[Rock_row][j]=='p'){
			res++;
			break;
		}else if(board[Rock_row][j]=='B' || board[Rock_row][j] =='R')break;
		j++;
	}
	j=Rock_col-1;
	while(j >=0){
		if(board[Rock_row][j]=='p'){
			res++;
			break;
		}else if(board[Rock_row][j]=='B' || board[Rock_row][j] =='R')break;
		j--;
	}
	return res;
    }
};
