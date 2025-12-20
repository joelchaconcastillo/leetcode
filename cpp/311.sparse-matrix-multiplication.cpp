class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
          int n = mat1.size(), m = mat2.size(), k = mat2[0].size();
	  // (n x m) (m x k) --> n x k
	  vector<vector<int> > res(n, vector<int> (k, 0));
	  for(int i = 0 ; i < n; i++){
	       for(int l = 0; l < m;l++){
		       if(mat1[i][l]==0)continue;
		  for(int j = 0 ; j < k; j++){
				  res[i][j] += mat1[i][l]*mat2[l][j];
			  }
		  }
	  }
	  return res;
    }
};
