class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int> > mat(m,vector<int>(n, 0));
        for(auto index:indices){
		for(int i = 0; i < m; i++) mat[i][index[1]]++;
		for(int j = 0 ;j < n; j++) mat[index[0]][j]++;
	}	
	int res =0;
	for(auto row:mat){
		for(auto col:row) res += (col%2!=0);
	}
	return res;
    }
};
