class Solution {
public:
    vector<int> solve(vector<vector<int> > &mat){
	    int n = mat.size(), m = mat[0].size();
	    vector<int>res;
	    int k = 0;
	    for(int i = 0; i < n; i++, k++){
		    int ii = i, j = 0;
		    vector<int> tmp;
		    while( ii >=0 && j <m) tmp.push_back(mat[ii--][j++]);
		    if(k%2==1)
		    reverse(tmp.begin(), tmp.end());
		    for(auto i:tmp)res.push_back(i);
	    }
	    for(int j = 1; j < m; j++, k++){
		    int ii = n-1, jj = j;
		    vector<int> tmp;
		    while(ii>=0 && jj < m) tmp.push_back(mat[ii--][jj++]);
		    if(k%2==1)
		    reverse(tmp.begin(), tmp.end());
		    for(auto i:tmp) res.push_back(i);
	    }
	    return res;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
	    return solve(mat);
    }
};
