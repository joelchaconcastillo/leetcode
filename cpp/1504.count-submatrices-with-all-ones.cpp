class Solution {
public:
    int solve(vector<vector<int> > &mat){
	int n = mat.size(), m = mat[0].size(), res = 0;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < m ; j++){
			if(mat[i][j]==0)continue;
			vector<bool> hasZeroCol(m,false);
			for(int ii = i; ii<n; ii++){
				if(mat[ii][j]==0)break;
				for(int jj = j; jj<m; jj++){
					if(mat[ii][jj]==0){
						hasZeroCol[jj]=true;
					}
					if(hasZeroCol[jj])break;
					res++;
				}
			}
		}
	}
	return res;    
    }
    int solve2(vector<vector<int> > &mat){
	    int n = mat.size(), m = mat[0].size();
	    vector<vector<int> > dp(n, vector<int> (m, 0));
	    for(int i = 0 ; i < n ; i++){
		    dp[i][0] = mat[i][0];
		    for(int j = 1; j < m; j++){
			    dp[i][j] = (dp[i][j-1]+mat[i][j])*mat[i][j];
		    }
	    }
	    int res = 0;
	    for(int i = 0 ;i  < n ; i++){
		    for(int j =  0; j < m; j++){
			    int min_width = dp[i][j];
			    for(int k = i; k>=0; k--){
				    min_width = min(min_width, dp[k][j]);
				    if(min_width==0)break;
				    res += min_width;
			    }
		    }
	    }
	    return res;
    }
    int solve3(vector<vector<int> > &mat){
	    int n = mat.size(), m = mat[0].size();
	    vector<int> height(m, 0);
	    int res = 0;
	    for(int i = 0 ; i < n ; i++){
		    for(int j = 0; j < m; j++){
			    if(mat[i][j]==0)height[j]=0;
			    else height[j]++;
		    }
		    int sum = 0;
		    vector<pair<int, int> > stack; //height, number of columns
		    for(int j = 0 ;j < m; j++){
			    int current_height = height[j];
			    int count_columns = 1;
			    while(!stack.empty() && stack.back().first >= current_height){
				    sum -= stack.back().first*stack.back().second;
				    count_columns += stack.back().second;
				    stack.pop_back();
			    }
			    stack.push_back({current_height, count_columns});
			    sum += current_height*count_columns;
			    res += sum;
		    }
	    }
	    return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
	    return solve3(mat);
	    return solve2(mat);
	    return solve(mat);
    }
};
/*
 
    0  1  1  0     0  1  2  0   3       0 1 2 0  0 1 1 0  0 1 2 0
    0  1  1  1     0  2  4  3   9  12   0 1 2 3  0 2 2 1  0 2 4 3
    1  1  1  0     1  4  7  0   12 24   1 2 3 0  1 3 3 1  1 4 7 0
   if g[i-1][j-1]==1 dp[i][j] = dp[i-1][j]+dp[i][j-1]
               0 1 2 0   3
               0 2 4 3   9 12
               1 4 7 0   12   24

   1 0 1    1 0 1   1 0 1
   0 1 0    0 1 0   
   1 0 1    1 0 1



   [[0,0,0],[0,0,0],[0,1,1],[1,1,0],[0,1,1]]


    0 0 0   0 0 0
    0 0 0   0 0 0
    0 1 1   0 1 2
    1 1 0   1 3 0
    0 1 1   0 3 2
 * */
