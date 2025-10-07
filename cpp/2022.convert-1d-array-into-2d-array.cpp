class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
	  
	  int N = original.size();
	  if(N!=(m*n))return {};
          vector<vector<int> > res(m, vector<int> (n,0));
	  for(int i = 0 ;i < N; i++){
		  res[i/n][i%n] = original[i];
	  }
	  //  1 2 3 4
	  //  1 . x
	  return res;
    }
};
