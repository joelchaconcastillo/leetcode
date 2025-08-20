class Robot {
public:
    int width, height;
    int row, col;
    int currentDirection;
    vector<string> dir2str = { "East","North","West", "South"};
    vector<int> deltaRow = {0,1,0,-1};
    vector<int> deltaCol = {1,0,-1,0};
    Robot(int width, int height):width(width), height(height){
	    currentDirection = 0;
	    row=0;
	    col=0;
    }
    bool isValid(int r, int c){
	    if(c<0 || c>=width) return false;
	    if(r<0 || r>=height)return false;
	    return true;
    }
    void step(int num) {
	    int perimeter = 2*(height+width-2); //TODO: difficult to spot!
	    if(num>=perimeter){
	       num %=perimeter;
	       if(col==0 && row==0 && currentDirection==0) currentDirection=3;// TODO: difficult to spot!
	    }

	    while(num){
	      if(currentDirection==0){
		      int takenCol = min(width-col-1, num);
		      num -=takenCol;
		      col += takenCol;
	      }else if(currentDirection==2){
		      int takenCol = min(col, num);
		      num -=takenCol;
		      col -= takenCol;
	      }else if(currentDirection==1){
		      int takenRow = min(height-row-1, num);
		      num -=takenRow;
		      row += takenRow;
	      }else if(currentDirection==3){
		      int takenRow = min(row, num);
		      num -=takenRow;
		      row -= takenRow;
	      }
	      if(num==0)break;
	      currentDirection++;
	      currentDirection%=4;
	    }
    }
    
    vector<int> getPos() {
       return {col, row}; 
    }
    
    string getDir() {
	    return dir2str[currentDirection];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
