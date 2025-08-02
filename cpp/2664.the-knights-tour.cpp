class Solution {
public:
    vector<tuple<int, int> > directions = {
	    {2,1}, {-2,1}, {2,-1}, {-2,-1}, 
	    {1,2}, {-1,2}, {-1,-2}, {1,-2}
    };
    void dfs(int m, int n, int r, int c, vector<vector<int> > &res, vector<vector<int>> &current, int step){
	    if(current[r][c]!=-1) return;
	    current[r][c] = step;
	    step++;
	    if(step == m*n){
		    res = current;
		    return;
	    }
	    for(auto [delta_row, delta_col]:directions){
		    int next_row = r+delta_row, next_col = c+delta_col;
		    if(next_row < 0 || next_row >=m)continue;
		    if(next_col < 0 || next_col >=n)continue;
		    dfs(m,n,next_row, next_col, res, current, step);
	    }
	    current[r][c] = -1;
    }
    vector<vector<int> > solve(int m, int n, int r, int c){
	    vector<vector<int> > res;
	    vector<vector<int>> current(m, vector<int> (n, -1));
	    dfs(m,n,r,c,res, current, 0);
	    return res;
    }
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
	    return solve(m,n,r,c);
    }
};
