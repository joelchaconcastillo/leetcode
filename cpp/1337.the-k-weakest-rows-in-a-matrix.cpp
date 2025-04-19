class Solution {
public:
    vector<int> solve(vector<vector<int> > &mat, int k){
	  int n = mat.size(), m = mat[0].size();
	  priority_queue<tuple<int, int>> pq;
	  for(int i = 0 ; i < n ; i++){
	     int counter = 0;
	     for(int j = 0 ; j < m; j++){//we can do binary search here!!
		    if(mat[i][j] == 1)counter++;
	     }
	     pq.push({counter, i});
	     if(pq.size()>k)pq.pop();
	  }
	  vector<int> res;
	  while(!pq.empty()){
		 auto [strong, idx]= pq.top(); pq.pop();
		 res.push_back(idx);
	  }
	  reverse(res.begin(), res.end());
	  return res;
	  
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       return solve(mat, k);
    }
};
