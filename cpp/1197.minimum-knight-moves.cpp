class Solution {
public:
    int solve(int x, int y){
	queue<tuple<int, int, int>> q;
	unordered_map<int, unordered_set<int>> visited;
	q.push({0, 0, 0});
	vector<tuple<int, int>> directions = {
	     {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, 
	     {-2, 1}, {-1, 2}, {1, 2}, {2,1}
	};
	while(!q.empty()){
		auto [ dist, r, c] = q.front(); q.pop();
		if(visited[r].count(c))continue;
		visited[r].insert(c);

		if(r==x && c==y)return dist;
		for(auto [delta_r, delta_c]:directions){
			int next_r = r + delta_r, next_c = c + delta_c;
		        if(visited[next_r].count(next_c))continue;
			q.push({dist+1, next_r, next_c});
		}
	}
	return -1;
    }
    int minKnightMoves(int x, int y) {
	    return solve(x, y);
    }
};
