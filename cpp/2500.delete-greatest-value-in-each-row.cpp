class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();
       vector<priority_queue<int> > v_pq(n);
       for(int i = 0 ; i < n; i++){
	       for(int j = 0 ; j < m; j++){
		       v_pq[i].push(grid[i][j]);
	       }
       }
       int res = 0;
       for(int j = 0; j < m; j++){
	  int current_max = INT_MIN;
	  for(int i = 0; i < n; i++){
	     current_max = max(current_max, v_pq[i].top()); v_pq[i].pop();
	  }
	  res+=current_max;
       }
       return res;
    }
};
