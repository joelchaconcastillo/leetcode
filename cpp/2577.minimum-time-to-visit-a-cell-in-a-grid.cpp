class Solution {
public:
    int solve(vector<vector<int> > &grid){
	//base..
	if(grid[0][1] >1 && grid[1][0]>1)return -1;
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
	vector<tuple<int, int> > directions = {
		        {-1,0},
		{0,-1},         {0,1},
                         {1, 0}
	};
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > pq;
	pq.push({0,0,0});
	dist[0][0] = 0;
	while(!pq.empty()){
	   auto [w,r,c] = pq.top(); pq.pop();
	   if(r==n-1 && c == m-1) return w;
	   if(dist[r][c]<w)continue;
	   for(auto [delta_r, delta_c]:directions){
	       int next_r = r+delta_r, next_c = c+delta_c;
	       if(next_r < 0 || next_r >=n) continue;
	       if(next_c < 0 || next_c >=m) continue;
	       int a = w, b = grid[next_r][next_c];
	       int delta = grid[next_r][next_c]-w;
               int next_w = max(grid[next_r][next_c] + (int)(delta%2==0), w + 1);

	       if(dist[next_r][next_c] <= next_w) continue;
	       dist[next_r][next_c] = next_w;
	       pq.push({next_w, next_r, next_c});
	   }
	}
	if(dist[n-1][m-1]==INT_MAX)return -1;
	return dist[n-1][m-1];
    }
    int minimumTime(vector<vector<int>>& grid) {
	return solve(grid);
    }
};
/*
Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7 

    0 1 3 2   0 2 3 4
    5 1 2 5   x 1 4 5
    4 3 8 6   x x x x
    t  pos
    0  (0,0)
    1  (1,1)
    2  (0,1)
    3  (0,2)
    4  (1,2)
    5  (0,3)
    6
    q --> (5,2,2), (5,1,3), (6,1,0), (7,1,3)

    1) if there is at least one neigh with reachable time then we can reach any other neighbour

 * */
