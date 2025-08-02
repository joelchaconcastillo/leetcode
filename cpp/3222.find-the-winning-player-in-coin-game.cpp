class Solution {
public:
    unordered_map<int, unordered_map<int, bool >> memo;
    bool dfs(int x, int y){
	    if(memo.count(x) && memo[x].count(y))return memo[x][y];
	    if(x<1 || y<4)return memo[x][y] = false;
	    if(!dfs(x-1, y-4)) return memo[x][y] = true;
	    return memo[x][y] = false;
    }
    string solve(int x, int y){
	    memo.clear();
	    if(dfs(x,y))return "Alice";
	    return "Bob";
    }
    string solve2(int x, int y){
	    int a = x, b = y/4;
	    return (min(a,b)%2)==1?"Alice":"Bob";
    }
    string winningPlayer(int x, int y) {
	    return solve2(x, y);
	    return solve(x, y);
    }
};
