class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > &mat){
	    int n = mat.size(), m = mat[0].size();
	    queue<tuple<int, int, int> > q;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0; j< m; j++){
			 if(mat[i][j]==0)q.push({i,j,0});
			 mat[i][j]=-1;
		    }
	    }
	    vector<tuple<int, int>>directions = {
		  {0,-1}, {1,0}, {0,1}, {-1,0}
	    };
	    while(!q.empty()){
		 auto [r,c,s] = q.front(); q.pop();
		 if(mat[r][c]!=-1)continue;
		 mat[r][c]=s;
		 for(auto [delta_x, delta_y] : directions){
	             int next_r = delta_x+r, next_c = delta_y+c;
		     if(next_r < 0 || next_r >=n)continue;
		     if(next_c < 0 || next_c >=m)continue;
		     if(mat[next_r][next_c]!=-1)continue;
		     q.push({next_r, next_c, s+1});
		 }
	    }
	    return mat;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	    return solve(mat);
    }
};
