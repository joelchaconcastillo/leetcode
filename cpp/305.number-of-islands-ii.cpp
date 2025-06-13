class Solution {
public:
    int islands = 0;
    unordered_map<int, int> parents, rank;
    int _find(int node){
	return (parents[node]!=node)?(parents[node]=_find(parents[node])):node;
    }
    void _union(int a, int b){
	  a = _find(a);
	  b = _find(b);
	  if(a==b)return;
	  islands--;
	  if( rank[a] > rank[b]) swap(a,b);
	  parents[a] = b;
	  if(rank[a] == rank[b]) rank[b]++;
    }
    vector<int> solve(int n, int m, vector<vector<int> > &positions){
	  vector<tuple<int, int> > directions = {
		 {-1,0}, {1, 0}, {0,1}, {0,-1}
	  };
	  vector<int> res;
	  for(auto position:positions){
	       int row = position[0], col = position[1];
	       int current_flatenized = row*m+col;
	       if(parents.count(current_flatenized)==0){
	       parents[current_flatenized]=current_flatenized;
	       islands++;
	       rank[current_flatenized]=1;
	       for(auto [delta_row, delta_col]: directions){
		    int next_row = row+delta_row, next_col = col+delta_col;
		    if(next_row < 0 || next_row >= n)continue;
		    if(next_col < 0 || next_col >= m)continue;
		    int next_flatenized = next_row*m+next_col;
		    if(parents.count(next_flatenized)==0)continue;
		    if( _find(next_flatenized)!= _find(current_flatenized)){
			_union(next_flatenized, current_flatenized);
		    }
	       }}
	       res.push_back(islands);
	  }
	  return res;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
	    return solve(m, n, positions);
    }
};
