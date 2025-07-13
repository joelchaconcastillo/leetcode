class Solution {
public:
    vector<int> solve(vector<vector<int> > &grid){
	    int n = grid.size(), m = grid[0].size();
	    unordered_map<int, int> freq;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m; j++){
			    freq[grid[i][j]]++;
		    }
	    }
	    int repeated=0, missing=0;
	    for(int i = 1 ; i <= n*n; i++){
		    if(freq[i] == 0)missing=i;
		    if(freq[i] >=2 )repeated=i;
	    }
	    return {repeated, missing};
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	    return solve(grid);
    }
};
