class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
         int n = matrix.size();	    
	 unordered_set<int> ref;
	 for(int i = 1; i <=n; i++)ref.insert(i);
	 for(int i = 0 ;i <n; i++){
		 unordered_set<int> tmp(matrix[i].begin(), matrix[i].end());
		 if(tmp != ref)return false;
	 }
	 for(int j = 0; j < n; j++){
		 unordered_set<int> tmp;
		 for(int i =0  ;i < n; i++) tmp.insert(matrix[i][j]);
		 if(ref!=tmp)return false;
	 }
	 return true;
    }
};
