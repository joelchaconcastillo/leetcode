class Solution {
public:
    bool bfs(vector<vector<int> > &dungeon, int threshold){
	 int n = dungeon.size(), m = dungeon[0].size();
	 queue<tuple<int, int, int>> q;
	 vector<tuple<int, int> > directions = {
	   {0,1},{1,0}
	 };
//	 [[-2,-3,3],[-5,-10,1],[10,30,-5]]
	 q.push({threshold+dungeon[0][0], 0, 0});//7
	 while(!q.empty()){
	    auto [t, r, c] = q.front(); q.pop();
	    if(t <=0) continue;
	    if(r==n-1 && c==m-1)return true;
	    for(auto [delta_r, delta_c] : directions){
	        int next_r = delta_r+r, next_c = delta_c+c;
		if(next_r < 0 || next_r>=n ||next_c <0 ||next_c>=m)continue;
		int next_t = t+dungeon[next_r][next_c];
		if(next_t <=0)continue;
		q.push({next_t, next_r, next_c});
	    }
	 }
	 return false;
    }
    int solve(vector<vector<int> > &dungeon){
	int n = dungeon.size(), m = dungeon[0].size();
	int lo = 1, hi = 10000;
	while(lo < hi){
	   int mid = lo+(hi-lo)/2;
	   if(bfs(dungeon, mid)){
		 hi = mid;
	   }else lo = mid+1;
	}
	return lo;
    }
    int solve2(vector<vector<int> > &dungeon){
	int n = dungeon.size(), m = dungeon[0].size();
	vector<vector<int> > dp(n+1, vector<int> (m+1, INT_MAX));
	dp[n-1][m] = dp[n][m-1]=1;//base case
	for(int i = n-1; i >= 0; i--){
	   for(int j = m-1; j>=0; j--){
	      int hp = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
	      dp[i][j] = max(1, hp);
	   }
	}
	return dp[0][0];
    }

    struct State {
        int min_health_required;
        int current_health;
    
        State(int min_h = INT_MAX, int cur_h = 0) : min_health_required(min_h), current_health(cur_h) {}
    };
    
    int solve3(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<State>> dp(n, vector<State>(m));
    
        // Initialize start position
        int start = dungeon[0][0];
        if (start >= 0)
            dp[0][0] = {1, start + 1};
        else
            dp[0][0] = {1 - start, 1};
    
        // Fill first row
        for (int j = 1; j < m; ++j) {
            auto prev = dp[0][j - 1];
            int cur_health = prev.current_health + dungeon[0][j];
            int min_req = prev.min_health_required;
            if (cur_health <= 0) {
                min_req += 1 - cur_health;
                cur_health = 1;
            }
            dp[0][j] = {min_req, cur_health};
        }
    
        // Fill first column
        for (int i = 1; i < n; ++i) {
            auto prev = dp[i - 1][0];
            int cur_health = prev.current_health + dungeon[i][0];
            int min_req = prev.min_health_required;
            if (cur_health <= 0) {
                min_req += 1 - cur_health;
                cur_health = 1;
            }
            dp[i][0] = {min_req, cur_health};
        }
    
        // Fill rest of the table
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                vector<State> options;
    
                for (auto [pi, pj] : vector<pair<int,int>>{{i-1,j}, {i,j-1}}) {
                    auto prev = dp[pi][pj];
                    int cur_health = prev.current_health + dungeon[i][j];
                    int min_req = prev.min_health_required;
                    if (cur_health <= 0) {
                        min_req += 1 - cur_health;
                        cur_health = 1;
                    }
                    options.push_back({min_req, cur_health});
                }
    
                // Pick path with lowest required initial health
                dp[i][j] = (options[0].min_health_required <= options[1].min_health_required) ? options[0] : options[1];
            }
        }
    
        return dp[n - 1][m - 1].min_health_required;
    }
    int recursive(vector<vector<int> > &dungeon, int i, int j, vector<vector<int> > &memo){
	int n = dungeon.size(), m = dungeon[0].size();
	if(i >= n || j>=m)return INT_MAX;
	if(i==n-1 && j == m-1)return max(1,1- dungeon[i][j]);
	if(memo[i][j] != -1) return memo[i][j];
	int right = recursive(dungeon, i+1, j, memo);
	int left = recursive(dungeon, i, j+1, memo);
	int need = min(right, left)-dungeon[i][j];// the minimum health needed --> min so far -current(i,j)
	return memo[i][j] = max(1, need);
    }
    int solve4(vector<vector<int> > &dungeon){
	   int n = dungeon.size(), m = dungeon[0].size();
	   vector<vector<int> > memo(n+1, vector<int> (m+1, -1));
	   return recursive(dungeon, 0, 0, memo);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
	return solve4(dungeon);
	return solve2(dungeon);
	return solve(dungeon);
	return solve3(dungeon);
    }
};
