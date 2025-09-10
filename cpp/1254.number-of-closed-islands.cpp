class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
	 vector<tuple<int, int> > directions = {
		 {-1,0}, {1,0}, {0,1}, {0,-1}
	 };
	 int n = grid.size(), m = grid[0].size();
	 int res = 0;
	 vector<vector<bool> > visited(n, vector<bool> (m, false));
	 for(int i = 0 ; i < n ;i++){
		 for(int j = 0 ; j <m ; j++){
			 if(visited[i][j])continue;
			 if(grid[i][j]==1)continue;
			 queue<tuple<int, int> > q;
			 q.push({i,j});
			 bool isIsland = true;
			 while(!q.empty()){
				 auto [row, col]= q.front(); q.pop();
				 if(visited[row][col])continue;
			          visited[row][col] = true;
				  if(row==0 || col==0 || row == n-1 || col == m-1) isIsland=false;
				  for(auto [delta_row, delta_col]:directions){
					  int next_row = row+delta_row;
					  int next_col = col+delta_col;
					  if( next_row < 0 || next_row == n)continue;
					  if(next_col < 0 || next_col == m)continue;
					  if(grid[next_row][next_col]==1)continue;
					  if(visited[next_row][next_col])continue;
					  q.push({next_row, next_col});
				  }
			 }
			 res += isIsland;
		 }
	 }
	 return res;
    }
};
