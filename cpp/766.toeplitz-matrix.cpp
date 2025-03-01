class Solution {
public:
    /*
     *  time: O(n*m)
     *  space: O(1)
     *  elapsed time: 3 min
     * */
    bool solve(vector<vector<int> > &matrix){
       int n = matrix.size(), m = matrix.front().size();
       bool hasSolution = true;
       for(int i = 0; i < n; i++){
	  pair<int, int> pos(i,0);
	  while(pos.first+1 < n && pos.second+1 < m){
	        if(matrix[pos.first][pos.second] != matrix[pos.first+1][pos.second+1]) return false;
	        pos.first++;
		pos.second++;
	  }
       }
       for(int j = 1; j < m; j++){
	  pair<int, int> pos(0,j);
	  while(pos.first+1 < n && pos.second+1 < m){
	        if(matrix[pos.first][pos.second] != matrix[pos.first+1][pos.second+1]) return false;
	        pos.first++;
		pos.second++;
	  }
       }
       return hasSolution;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
       return solve(matrix);
    }
};
/*
[ [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]]

 * */
