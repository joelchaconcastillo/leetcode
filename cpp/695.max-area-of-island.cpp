class Solution {
public:
    int solve(vector<vector<int> >&grid){
	int n = grid.size(), m = grid[0].size(), res = 0;
	vector<vector<int > > dp(n, vector<int> (m, 0));
	dp[0][0] = grid[0][0];
	res = max(res, dp[0][0]);
	for(int i = 1; i < n; i++){
		dp[i][0] = (grid[i][0])*(grid[i][0]+dp[i-1][0]);
		res = max(res, dp[i][0]);
	}
	for(int j = 1; j < m; j++){
	       	dp[0][j] = (grid[0][j])*(grid[0][j]+dp[0][j-1]);
		res = max(res, dp[0][j]);
	}
	for(int i = 1 ; i <n ; i++){
	   for(int j = 1 ;j < m ; j++){
	      if(grid[i][j]==0)continue;
	      dp[i][j] = dp[i][j-1]+grid[i][j];
	   }
	   for(int j = m-2; j>=0; j--){
	      if(grid[i][j]==0)continue;
		   dp[i][j] = max(dp[i][j], dp[i][j+1]);
	   }
	}
	for(int i = 0 ; i < n;i++){
	   for(int j = 0 ; j < m ; j++){
		   cout << dp[i][j] <<" ";
	   }cout <<endl;
	}
	return res;
    }
    int solve2(vector<vector<int> >&grid){
	int n = grid.size(), m = grid[0].size(), res = 0;
	vector<tuple<int, int> > direction = {
	   {0, 1}, {0, -1}, {1,0}, {-1,0}
	};
	for(int i = 0 ; i <n ; i++){
	   for(int j = 0 ;j < m ; j++){
		queue<tuple<int, int> > q;
		q.push({i, j});
		int size = 0;
		while(!q.empty()){
		   auto [r,c] = q.front(); q.pop();
		   if(grid[r][c]==0)continue;
		   grid[r][c]=0;
		   size++;
		   for(auto [delta_r, delta_c]: direction){
		       int next_r = delta_r+r, next_c = delta_c+c;
		       if(next_c <0 || next_c >=m || next_r<0 ||next_r>=n)continue;
		       q.push({next_r, next_c});
		   }
		}
		res = max(res, size);
	   }
	}
	return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
	return solve2(grid);
    }
};
