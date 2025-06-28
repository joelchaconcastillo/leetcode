class Solution {
public:
    int n, m;
    vector<tuple<int, int, string> > directions = {
	    {-1,0,"u"}, {1,0,"d"}, {0,1,"r"}, {0,-1,"l"}
    };
    bool can_be_moved(int row, int col, vector<vector<int> > &maze){
	    int n = maze.size(), m = maze.front().size();
	    if(row < 0 || row >=n) return false;
	    if(col < 0 || col >=m) return false;
	    if(maze[row][col]==1)return false;
	    return true;
    }
    string solve(vector<vector<int> > &maze, vector<int> &ball, vector<int> &hole){
	    string current="";
	    n = maze.size(), m = maze.front().size();
	    typedef tuple<int, string, int, int > my_type;
	    priority_queue<my_type, vector<my_type>, greater<>> pq;
	    vector<vector<tuple<int, string>> > dists(n, vector<tuple<int, string>> (m, {INT_MAX, ""}));
	    dists[ball[0]][ball[1]]={0,""};
	    pq.push({0, "",ball[0], ball[1]});
	    while(!pq.empty()){
		    auto [dist, path, row, col] = pq.top(); pq.pop();
		    for(auto [delta_row, delta_col, letter]:directions){
			 int next_row = row, next_col = col, next_dist = dist;
			 bool was_moved=false;
			 while(can_be_moved(next_row+delta_row, next_col+delta_col, maze)){
			       next_row += delta_row;
			       next_col += delta_col;
			       next_dist++;
			       was_moved=true;
			       if(hole[0] == next_row && hole[1] == next_col)break;
			 }
			 if(!was_moved)continue;
			 tuple<int, string> kv(next_dist, path+letter);
			 if( kv >= dists[next_row][next_col]) continue;
			 dists[next_row][next_col] = kv;
			 pq.push({next_dist, path+letter, next_row, next_col});
		    }
	    }
	    if(get<0>(dists[hole[0]][hole[1]])==INT_MAX)return "impossible";
	    return get<1>(dists[hole[0]][hole[1]]);
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
	    return solve(maze, ball, hole);
    }
};
/*
 [
     [0,0,0,0,B,0,0],
     [0,0,1,0,0,1,0],
     [0,0,0,0,1,0,0],
     [0,0,0,0,0,H,1]]
 * */
