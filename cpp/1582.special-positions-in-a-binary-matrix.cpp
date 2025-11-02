class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int n = mat.size(), m = mat[0].size();
       vector<int> rows(n, 0), cols(m, 0);
       int res = 0;
       for(int i = 0 ;i < n; i++){
	       for(int j = 0 ; j < m; j++){
		       rows[i] += mat[i][j]==1;
		       cols[j] += mat[i][j]==1;
	       }
       }
       for(int i = 0 ; i< n; i++){
	       for(int j = 0 ; j < m; j++){
		       if(mat[i][j] == 1 && rows[i] ==1 && cols[j]==1)res++;
	       }
       }
       return res;
    }
};
