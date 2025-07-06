class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > &land){
	    vector<vector<int> > res;
	    int n = land.size(), m = land[0].size();
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m; j++){
			    if(land[i][j] == 0)continue;
			    queue<tuple<int, int> > q;
			    q.push({i,j});
			    vector<tuple<int, int> > directions ={
				    {0,1}, {0,-1}, {1,0}, {-1,0}
			    };
			    pair<int, int> minPos(n+1, m+1), maxPos(-1, -1);
			    while(!q.empty()){
				    auto [row, col] = q.front(); q.pop();
				    if(land[row][col]==0)continue;
				    land[row][col] = 0;
				    minPos = min(minPos, {row, col});
				    maxPos = max(maxPos, {row, col});
				    for(auto [delta_row, delta_col]:directions){
					    int next_row = row+delta_row;
					    int next_col = col+delta_col;
					    if(next_row < 0 || next_row >=n)continue;
					    if(next_col < 0 || next_col >=m)continue;
					    if(land[next_row][next_col]==0)continue;
					    q.push({next_row, next_col});
				    }
			    }
			    res.push_back({ minPos.first, minPos.second, maxPos.first, maxPos.second});
		    }
	    }
	    return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
	    return solve(land);
    }
};
