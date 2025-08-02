class Solution {
public:
    struct my_hash{
	    size_t operator ()(const tuple<int, int> &slope) const{
		    auto &[a,b] = slope;
		    size_t hash1 = hash<int>{}(a);
		    size_t hash2 = hash<int>{}(b);
		    return hash1 ^ (hash2<<1);
	    }
    };
    tuple<int, int> get_slope(vector<int> &point_a, vector<int> &point_b){
	    int dx = point_a[0]-point_b[0];
	    int dy = point_a[1]-point_b[1];
	    //int gcd = __gcd(abs(dy), abs(dx));
	    int _gcd = gcd(dy, dx);
	    int sign = dx*dy>=0?1:-1;
	    if(dy == 0) return {0, sign};
	    if(dx == 0) return {sign, 0};
	    return {sign*abs(dy)/_gcd, abs(dx)/_gcd};
    }
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs(unordered_map<int, unordered_map<tuple<int, int>, int, my_hash> > &slopes, int n, int mask){
	    //if(n==0) return __builtin_popcount(mask);
	    if(n==0) return mask;
	    if((mask & (1<<n) ) == 0 ) return dfs(slopes, n-1, mask); //skip used bits
	    if(memo.count(n) && memo[n].count(mask))return memo[n][mask];
	    int res = INT_MAX;
	    for(auto [sl, bitsOn]:slopes[n]){
		    res = min(res, dfs(slopes, n-1, mask & (~bitsOn))+1);//adding a line on that slope
	    }
	    return memo[n][mask] = res;
    }
    int solve(vector<vector<int> > &points){
	    if(points.size()<=1)return 1;
	    memo.clear();
	    unordered_map<int, unordered_map<tuple<int, int>, int, my_hash > > slopes;
	    // 0, {slope 1}, = 001011
	    int n = points.size();
	    for(int i = 0 ; i <n ; i++){
		    for(int j = 0; j < i; j++){
			    auto slope = get_slope(points[i], points[j]);
			    slopes[i][slope] |= (1<<i) | (1<<j);
		    }
	    }
	    return dfs(slopes, n-1, (1<<n)-1);
    }
    int minimumLines(vector<vector<int>>& points) {
	    return solve(points);
    }
};
