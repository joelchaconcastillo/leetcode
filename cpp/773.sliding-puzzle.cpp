#define INT_MAX 100000
class Solution {
public:
    vector<vector<int> > target_board = {
	    {1,2,3},{4,5,0}};
    vector<tuple<int,int> > direction = {
	    {0,-1}, {-1,0}, {0,1}, {1, 0}};
    map<vector<vector<int> >, int> marked;
    void dfs(vector<vector<int> > &board, int c_r, int c_c, int score=0){
	if(marked.count(board) && marked[board]<=score) return;
	marked[board]=score;
	score++;
	for(auto [r,c]:direction){
	   int r_delta = c_r+r, c_delta = c_c+c;
	   if(r_delta<0 || r_delta >=2)continue;
	   if(c_delta<0 || c_delta >=3)continue;
	   swap(board[c_r][c_c], board[r_delta][c_delta]);
	   dfs(board, r_delta, c_delta, score);
	   swap(board[c_r][c_c], board[r_delta][c_delta]);
	}
    }
    int bfs(vector<vector<int> >&board, int row, int col){
	queue<pair<vector<vector<int>>, tuple<int, int> >> q;
	set<vector<vector<int> > > visited;
	q.push({board, {row, col}});
	int res = -1, level = 0;
	while(!q.empty()){
	    queue<pair<vector<vector<int>>, tuple<int, int> >> tmp;
	    while(!q.empty()){
	      auto [cu, pp] = q.front(); q.pop();
	      if(visited.count(cu)) continue;
	      visited.insert(cu);
	      auto [c_r, c_c] = pp;
	      if(cu == target_board) return level;
   	      for(auto [r,c]:direction){
	        int r_delta = c_r+r, c_delta = c_c+c;
	        if(r_delta<0 || r_delta >=2)continue;
	        if(c_delta<0 || c_delta >=3)continue;
	        swap(cu[c_r][c_c], cu[r_delta][c_delta]);
	        if(!visited.count(cu))
	        tmp.push({cu, {r_delta, c_delta}});
	        swap(cu[c_r][c_c], cu[r_delta][c_delta]);
	      }
	   }
	      q=tmp;
	      level++;
	}
	return res;
    }
    int solve(vector<vector<int>> &board){
	marked.clear();
	int c_r=0, c_c=0;
	for(int i = 0; i < 2; i++){
	   for(int j = 0 ; j < 3; j++){
		   if(board[i][j] == 0){
			   c_r=i, c_c=j;
			   break;
		   }
	   }
	}
	//return bfs(board, c_r, c_c);
	dfs(board, c_r, c_c);
	if(marked.count(target_board))return marked[target_board];
	return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
	return solve(board);
    }
};
/*

   1 2 3
   4 x 5
     
     1 2 3
     4 5 x
     
     1 x 3
     4 2 5   

 * */
