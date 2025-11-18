class Solution {
public:
    int solve(vector<vector<char>>& grid) {
	int n = grid.size(), m = grid[0].size();
	queue<tuple<int, int>> q;
	vector<tuple<int, int> > directions = {
		{0,-1}, {0,1}, {1,0}, {-1,0}
	};
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ;j < m; j++){
			if(grid[i][j] == '*'){
				q.push({i, j});
				break;
			}
		}
		if(!q.empty())break;
	}
	int levels = 0;
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	auto [i,j] = q.front();
	visited[i][j] = true;
	while(!q.empty()){
		int _sz = q.size();
		while(_sz--){
		   auto [row, col]= q.front(); q.pop();
		   if(grid[row][col]=='#'){
			   return levels;
		   }
		   for(auto [delta_r, delta_c]:directions){
			   int next_row = row+delta_r, next_col = col+delta_c;
			   if(next_row < 0 || next_row >=n)continue;
			   if(next_col < 0 || next_col >=m)continue;
			   if(grid[next_row][next_col] == 'X')continue;
			   if(visited[next_row][next_col])continue;
			   visited[next_row][next_col]=true;
			   q.push({next_row, next_col});
		   }
		}
		levels++;
	}
	return -1;
    }
    int getFood(vector<vector<char>>& grid) {
	    return solve(grid);
    }
};
