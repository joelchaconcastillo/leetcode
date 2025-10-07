class Solution {
public:
    #define MAX_VALUE INT_MAX/2
    vector<tuple<int, int> > directions = {
	    {-1,0}, {1,0},
	    {0,-1}, {0,1}
    };
    int shortestPathAllKeys(vector<string>& grid) {
        pair<int, int> start;
	long long target_locks = 0;
	int n = grid.size(), m = grid[0].size();
	int lenMask = 0;
	for(int i = 0 ; i <n ;i++){
		for(int j = 0; j < m ; j++){
			if(grid[i][j] == '@') start = {i,j};
			if(islower(grid[i][j])){
				int bit = grid[i][j]-'a';
			       	target_locks|= (1<<bit);
				lenMask = max(lenMask, bit+1);
			}
		}
	}
	queue<tuple<int, int, long long> > q;
	q.push({start.first, start.second, 0});
	vector<vector<vector<bool> > > visited(n, vector<vector<bool>>(m, vector<bool> (64, false)));
	int level = 0;
	while(!q.empty()){
		int sz=q.size();
		for(int i = 0 ; i < sz; i++){
		  auto [row, col, mask] = q.front(); q.pop();
		  if(visited[row][col][mask])continue;
		  visited[row][col][mask]=true;
		  if(mask == target_locks) return level;
		  for(auto [delta_row, delta_col]:directions){
			int next_row = row+delta_row, next_col = col+delta_col;
			long long next_mask = mask;
			if(next_row <0 || next_row>=n || next_col<0 || next_col>=m)continue;
			if(islower(grid[next_row][next_col])){
				int bit = grid[next_row][next_col]-'a';
				next_mask |= (1LL<<bit);
			}else if(isupper(grid[next_row][next_col])){
				int bit = grid[next_row][next_col]-'A';
				if(!(mask & (1LL<<bit)))continue;
			}else if(grid[next_row][next_col]=='#')continue;
			if(visited[next_row][next_col][next_mask])continue;
			q.push({next_row, next_col, next_mask});
		  }
		}
		level++;
	}
	return -1;
    }
};
