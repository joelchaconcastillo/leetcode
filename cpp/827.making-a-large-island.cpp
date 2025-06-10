class Solution {
public:
    int solve(vector<vector<int>> &grid){
	int n = grid.size(), m = grid[0].size();
	unordered_map<int, int> islands;
	int current_island = 2;
	vector<tuple<int, int> > directions ={
	   {0,-1}, {0,1}, {-1,0}, {1,0}
	};
	int res = 0;
	for(int i = 0 ; i < n; i++){
	   for(int j = 0; j < m ;j++){
	     if(grid[i][j]!=1)continue;
	       queue<tuple<int, int>>q;
	       q.push({i,j});
	       int _size = 0;
	       while(!q.empty()){
		    auto [r, c] = q.front(); q.pop();
		    if(grid[r][c]!=1)continue;
		    grid[r][c] = current_island;
		    _size++;
		    for(auto [delta_r, delta_c] : directions){
			int next_r = r + delta_r, next_c = c + delta_c;
			if(next_r < 0 || next_r >=n) continue;
			if(next_c < 0 || next_c >=n) continue;
			if(grid[next_r][next_c] != 1)continue;
			q.push({next_r, next_c});
		    }
	       }
	       res = max(res, _size);
	       islands[current_island]=_size;
	       current_island++;
	   }
	}
	for(int i = 0 ; i < n; i++){
	   for(int j = 0 ; j < m; j++){
	       if(grid[i][j]!=0)continue;
	       unordered_set<int> taken;
	       int sum = 1;
	       for(int ii = 0; ii < 4; ii++){
		   auto [dr1, dc1] = directions[ii];
		   int r1 = dr1+i, c1 = dc1+j;
		   if(r1<0 || c1<0)continue;
		   if(r1>=n || c1 >=n)continue;
		   if(taken.count(grid[r1][c1]))continue;
		   taken.insert(grid[r1][c1]);
		   sum += islands[grid[r1][c1]];
	       }
	       res = max(res, sum);
	   }
	}
	if(res == 0 && n>0) res=1;
	return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
/*
 [
    [0,0,0,0,0,0,0],
    [0,1,1,1,1,0,0],
    [0,1,0,0,1,0,0],
    [1,0,1,0,1,0,0],
    [0,1,0,0,1,0,0],
    [0,1,0,0,1,0,0],
    [0,1,1,1,1,0,0]]
 * */
