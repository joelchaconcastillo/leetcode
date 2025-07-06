class Solution {
public:

    vector<vector<int> > solve(vector<vector<int>> &board){
	    int n = board.size(), m = board.front().size();
	    bool hasCandies=true;
	    while(hasCandies){
	       set<pair<int, int>> to_crush;
	       hasCandies=false;
  	       for(int i = 0 ; i < n; i++){
  	  		    for(int j = 0; j < m; j++){
				    if(board[i][j] == 0)continue;
				    if( j>0 && j+1<m && board[i][j-1] == board[i][j] && board[i][j+1]==board[i][j]){
					    hasCandies=true;
					    to_crush.insert({i, j-1});
					    to_crush.insert({i, j});
					    to_crush.insert({i, j+1});
				    }
				    if(i > 0 && i+1 < n && board[i-1][j] == board[i][j] && board[i+1][j] == board[i][j]){
					    hasCandies=true;
					    to_crush.insert({i-1, j});
					    to_crush.insert({i, j});
					    to_crush.insert({i+1, j});
				    }
  	  		    }
  	       }
	       //remove them
	       for(int j = 0 ; j < m; j++){
		       vector<int> wholeColumn;
		       for(int i = 0 ; i < n; i++){//ignore marked cells
			       if(to_crush.count({i,j}))continue;
			       wholeColumn.push_back(board[i][j]);
		       }
		       int pos = n-1;
		       for(int i = wholeColumn.size()-1; i>=0; i--, pos--){
			       board[pos][j] = wholeColumn[i];
		       }
		       while(pos>=0) board[pos--][j]=0;
	       }
	    }
	    return board;
    }
    void printBoard(vector<vector<int> > &board){
	    for(auto row:board){
		    for(auto col:row){
			    cout << col <<"   ";
		    }cout <<endl;
	    }
	    cout << endl;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
	    return solve(board);
    }
};
