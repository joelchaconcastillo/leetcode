class Solution {
public:
    /*
     * time: O(n log n)
     * space: O(n)
     * */
    long long solve(vector<vector<int>> &grid, vector<int> &limits, int k){
	 priority_queue<tuple<int, int>>pq;
	 int n = grid.size(), m = grid.front().size();
	 for(int i = 0 ; i < n; i++){
             for(int j = 0; j < m; j++){
		 pq.push({grid[i][j], i});
	     }
	 }
	 long long sum = 0;
	 while(k && !pq.empty()){
            auto [val, i] = pq.top(); pq.pop();
	    if(limits[i]==0)continue;
	    sum +=val;
	    limits[i]--;
	    k--;
	 }
	 return sum;
    }
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
       return solve(grid, limits, k); 
    }
};
