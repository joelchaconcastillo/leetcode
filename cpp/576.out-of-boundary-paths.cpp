class Solution {
public:
    int m, n;
    const long long MOD = 1e9+7;
    vector<tuple<int,int> > directions = {
	    {-1,0},
	    {1,0},
	    {0,1},
	    {0,-1}
    };
    struct _hash {
	    long long operator ()(const tuple<int, int, int> &A)const{
		    auto &[x,y,z] = A;
		    long long h1 = hash<int>{}(x);
		    long long h2 = hash<int>{}(y);
		    long long h3 = hash<int>{}(z);
		    return h1 ^ (h2<<1) ^ (h3<<1);
	    }
    };
    unordered_map<tuple<int, int, int>, int, _hash> memo;
    int dfs(int row, int col, int maxMove){
	    if(row < 0 || row >= m) return 1;
	    if(col < 0 || col >= n) return 1;
	    if(maxMove <= 0 ) return 0;
	    tuple<int, int, int> key(row, col, maxMove);
	    if(memo.count(key))return memo[key];
	    int res = 0;
	    for(auto [delta_row, delta_col]:directions){
		    int next_row = delta_row + row;
		    int next_col = delta_col + col;
		    res = (res + dfs(next_row, next_col, maxMove-1))%MOD;
	    }
	    return memo[key] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
	this->m = m;
	this->n = n;
	cout << endl;
        return dfs(startRow, startColumn, maxMove);
    }
};
