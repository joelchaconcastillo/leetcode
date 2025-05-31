
class Solution {
public:
    vector<int> pa, rank;
    int _find(int a){
	if(a==pa[a]) return a;
	return ( pa[a] = _find(pa[a]));
    }
    void _union(int a, int b){
	 a = pa[a];
	 b = pa[b];
	 if(a==b)return;
	 if(rank[a] > rank[b]) swap(a, b);
	 pa[b] = a;
	 if(rank[a]==rank[b])rank[a]++;
    }
    int solve1(vector<vector<int>> &stones){
	int n = stones.size();
	pa.assign(n, 0);
	rank.assign(n, 0);
	for(int i = 0 ; i < n ;i++)pa[i]=i;
	for(int i = 0 ; i < n; i++){
	   for(int j = i+1; j<n; j++){
	       if(stones[i][0] != stones[j][0] && stones[i][1] != stones[j][1])continue;
	       if( _find(i) == _find(j) ) continue;
	       _union(i, j);
	   }
	}
	int res = 0;
	for(int i = 0 ; i < n; i++){
	   res += (_find(i) == i);
	}
	return n-res;
    }
    void dfs(vector<vector<int>> &stones, int idx, vector<bool> &visited){
	 int n = stones.size();
	 if(visited[idx]) return;
	 visited[idx]=true;
	 for(int i = 0; i < n; i++){
	    if(i==idx)continue;
	    if(stones[idx][0]!=stones[i][0] && stones[idx][1] != stones[i][1])continue;
	    dfs(stones, i, visited);
	 }
    }
    int solve2(vector<vector<int>> &stones){
        int n = stones.size();
	vector<bool> visited(n, false);
	int res = 0;//this indicates the unique components...
	for(int i = 0 ; i < n ;i++){
	    if(visited[i])continue;
	    res++;
	    dfs(stones, i, visited);
	}
	return n-res;
    }
    int removeStones(vector<vector<int>>& stones) {
	return solve2(stones);
	return solve1(stones);
    }
};
/*
    x      stone_1, stone_2, stone_3, ..., stone_n
 0  0       0       0           0
 1  0       1       1           1        
 2  0       1       
 3
 4
 5
 6

dp[i][j] = max number of additions considering at max i stones and until j stone

dp[i][j] = max({
                 dp[i-1][j-k]+1, //if stone_k is not attaking stoke_j
		 dp[i-1][j],



 * */
