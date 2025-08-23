class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       int n = img.size(), m = img[0].size();
       auto res = img;
       for(int i = 0 ; i < n ; i++){
	       for(int j = 0; j < m; j++){
		       int sum = 0, k=0;
		       for(int ii = max(0, i-1); ii <  min(n,i+2); ii++){
			       for(int jj = max(0, j-1); jj < min(m,j+2); jj++){
				       k++;
				       sum +=img[ii][jj];
			       }
		       }
		       res[i][j] = sum/k;
	       }
       }       
       return res;
    }
};
