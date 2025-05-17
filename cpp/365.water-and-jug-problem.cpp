class Solution {
public:
    bool dfs(int x, int y, int max_x, int max_y, int target, set<tuple<int, int>> &visited){
         if(x+y == target)return true;
	 bool res = false;
	 if(visited.count({x, y}))return false;
	 visited.insert({x, y});
	 res |= dfs(max_x, y, max_x, max_y, target, visited);
	 res |= dfs(x, max_y, max_x, max_y, target, visited);
	 res |= dfs(0, y, max_x, max_y, target, visited);
	 res |= dfs(x, 0, max_x, max_y, target, visited);
	 int delta1 = min(x, max(0, max_y-y));
	 res |= dfs(x-delta1, y+delta1, max_x, max_y, target, visited);
	 int delta2 = min(y, max(0, max_x-x));
	 res |= dfs(x+delta2, y-delta2, max_x, max_y, target, visited);

	 return res;
    }
    bool solve2(int x, int y, int target){
	 set<tuple<int, int>> visited;
	 return dfs(0, 0, x, y, target, visited);
    }
    bool solve1(int x, int y, int target){
	 if(target == 0)return true;
	 if(x+y < target)return false;

	 int z = __gcd(x,y);
	 return target%z==0;
    }
    bool canMeasureWater(int x, int y, int target) {
//	 return solve1(x, y, target);
	 return solve2(x, y, target);
    }
};
