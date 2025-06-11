/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<tuple<int, int> > directions = {
      {-1, 0}, {0,-1}, {1,0}, {0,1}
    };
    void dfs(Robot &robot, unordered_map<int, unordered_map<int, bool> > &visited, int row, int col, int direction){
	  if(visited[row][col])return;
	  visited[row][col] = true;
	  robot.clean();
	  for(int i = 0 ; i < 4; i++){//0,D, 1,R, 2,U, 3,L
	      int next_direction = (direction+i)%4;
	      auto [delta_row, delta_col] = directions[next_direction];
	      int next_row = row+delta_row, next_col = col+delta_col;
	      if(!visited[next_row][next_col] && robot.move()){
	         dfs(robot, visited, next_row, next_col, next_direction);
		 robot.turnLeft(); robot.turnLeft();//orient it opposite direction
		 robot.move();//move it
		 robot.turnLeft(); robot.turnLeft();//correct current direction
	      }
	      robot.turnLeft();
	  }
    }
    void solve(Robot& robot){
	 unordered_map<int, unordered_map<int, bool > > visited;
	 dfs(robot, visited, 0, 0, 0);
    }
    void cleanRoom(Robot& robot) {
         return solve(robot);
    }
};
