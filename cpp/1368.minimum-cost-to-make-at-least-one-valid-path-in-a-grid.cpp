#define INT_MAX 1000000
class Solution {
public:
    vector<tuple<int, int, int> > directions = {
       {0,-1,2}, {0, 1, 1}, {1, 0, 3}, {-1, 0, 4}
    };
    int n, m;
    vector<vector<int> > dists;
    int backtracking(int r, int c, vector<vector<int> > &grid, vector<vector<bool> > &marked, int current=0){
	   if(r == n-1 && c == m-1){
		 return 0;
	   }
	   if(dists[r][c] < current)return dists[r][c];
	   if(marked[r][c])return INT_MAX;
	   marked[r][c]=true;
	   int res = INT_MAX;
	   for(auto [n_r, n_c, d]:directions){
		 int next_r = n_r+r, next_c = n_c+c;
		 if(next_r < 0 || next_r >=n)continue;
		 if(next_c < 0 || next_c >=m)continue;
		 int score = (grid[r][c] != d);
		 res = min(res, backtracking(next_r, next_c, grid, marked, current+score)+score);
	   }
	   marked[r][c]=false;
	   return dists[r][c] = res;
    }
    bool relaxGrid(int n, int m, vector<vector<int> > &dp, vector<vector<int> > &grid){
	    auto prev = dp;
	    //forward
	    for(int i = 1; i < n; i++) dp[i][0] = min(dp[i][0], (grid[i-1][0]!=3) + dp[i-1][0]);
	    for(int j = 1; j < m; j++) dp[0][j] = min(dp[0][j], (grid[0][j-1]!=1) + dp[0][j-1]);
	    for(int i = 1; i <n; i++){
		    for(int j = 1; j < m; j++){
			   dp[i][j] = min(dp[i][j], (grid[i-1][j]!=3)+dp[i-1][j]);
			   dp[i][j] = min(dp[i][j], (grid[i][j-1]!=1)+dp[i][j-1]);
		    }
	    }
	    //backwards
	    for(int i = n-2; i>=0; i--) dp[i][0] = min(dp[i][0], (grid[i+1][0]!=4)+dp[i+1][0]);
	    for(int j = m-2; j>=0; j--) dp[0][j] = min(dp[0][j], (grid[0][j+1]!=2)+dp[0][j+1]);
	    for(int i = n-2; i >=0; i--){
		for(int j = m-2; j >=0; j--){
			dp[i][j] = min(dp[i][j], (grid[i+1][j]!=4)+dp[i+1][j]);
			dp[i][j] = min(dp[i][j], (grid[i][j+1]!=2)+dp[i][j+1]);
		}
	    }
	    return prev != dp;
    }
    int solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int> > dp(n,vector<int> (m, INT_MAX));
	    dp[0][0]=0;
	    while(relaxGrid(n, m , dp, grid));
	    return dp.back().back();
    }
    int solve2(vector<vector<int> > &grid){
	    n = grid.size(), m = grid[0].size();
	    dists.assign(n, vector<int> (m, INT_MAX));
	    vector<vector<bool> > marked(n, vector<bool>(m, false));
	    return backtracking(0,0, grid, marked);
    }
    int solve3(vector<vector<int> > &grid){
	   int n = grid.size(), m = grid[0].size();
	   typedef tuple<int, int, int>  my_type;
	   priority_queue< my_type, vector<my_type>, greater<>> pq;
	   pq.push({0, 0, 0});
	   vector<vector<int> > dists(n, vector<int> (m, INT_MAX));
	   while(!pq.empty()){
		 auto [w, r, c] = pq.top(); pq.pop();
	         for(auto [n_r, n_c, d]:directions){
		   int next_r = n_r+r, next_c = n_c+c;
		   if(r == n-1 && c == m-1) return w;
		   if(next_r < 0 || next_r >=n)continue;
		   if(next_c < 0 || next_c >=m)continue;
		   int score = (grid[r][c] != d);
		   int next_dist = w+score;
		   if(next_dist >= dists[next_r][next_c])continue;
		   dists[next_r][next_c] = next_dist;
		   pq.push({next_dist, next_r, next_c});
	         }
	   }
	   return -1;
    }
    int minCost(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
/*

Input: grid = 
     1 2    -> <-
     4 3    ^  d
     	    
Output: 1

Last case:     [
    [R,D,D,D],
    [L,L,R,L],
    [U,D,D,U],
    [D,L,L,D],
    [D,L,R,D],
    [U,R,U,D],
    [D,D,R,L]]

 */

