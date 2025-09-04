class Solution {
public:
    int solve1(int m, int n, vector<vector<int>>& indices) {
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
    int solve2(int m, int n, vector<vector<int>>& indices) {
	    vector<int> rowCont(m,0), colCont(n, 0);
	    for(auto index:indices){
		    rowCont[index[0]]++;
		    colCont[index[1]]++;
	    }
	    int evenRow = 0, oddRow=0, evenCol=0, oddCol=0;
	    for(auto sumRow:rowCont){
		    if(sumRow%2==1)oddRow++;
		    else evenRow++;
	    }
	    for(auto sumCol:colCont){
		    if(sumCol%2==1)oddCol++;
		    else evenCol++;
	    }
	    return evenCol*oddRow + oddCol*evenRow;
    }
    int oddCells(int m, int n, vector<vector<int>>& indices) {
	    return solve2(m, n, indices);
    }
};
