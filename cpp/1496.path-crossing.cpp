class Solution {
public:
    bool isPathCrossing(string path) {
         pair<int, int> current(0,0);	    
	 unordered_map<char, pair<int, int>>directions = {
		 {'N', {0,-1}},
		 {'S', {0,1}},
		 {'E', {-1,0}},
		 {'W', {1,0}}
	 };
	 set<pair<int, int>>visited;
	 visited.insert(current);
	 for(auto direction:path){
		 auto [delta_row, delta_col] = directions[direction];
		 current.first += delta_row;
		 current.second += delta_col;
		 if(visited.count(current))return true;
		 visited.insert(current);
	 }
	 return false;
    }
};
