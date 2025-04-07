class Solution {
public:
	// time: O(k*n*n)
    double solve(int n, int k, int row, int column){
	    vector<vector<int> > deltas = {
		    {-2, -1},    {-2, 1},
		{-1, -2},              {-1, 2},
	       {1, -2},                  {1, 2},
	       {2, -1},                 {2, 1}
	    };
	    map<pair<int, int>, double> q;
	    q[{row, column}]=1.0;
	    double total_probability = 0.0;
	    for(int i = 0 ; i <= k; i++){
	          total_probability = 0.0;
	          map<pair<int, int>, double> q_next;
		  for(auto ii:q){
		     int _r = ii.first.first, _c = ii.first.second;
		     double _p = ii.second;
		     for(auto delta: deltas){
		        int delta_row = _r+delta[0];
		        int delta_col = _c+delta[1];
			if(delta_row <0 || delta_row >=n)continue;
			if(delta_col <0 || delta_col >=n)continue;
			q_next[{delta_row, delta_col}] += _p/8.0;
		     }
		     total_probability += _p;
		  }
		  q = q_next;
	    }
	    return total_probability;
    }
    double knightProbability(int n, int k, int row, int column) {
	    return solve(n, k, row, column);
    }
};
