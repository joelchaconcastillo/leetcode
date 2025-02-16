class Solution {
public:
    double score(vector<vector<int> > & squares, double split){
	double upArea = 0.0, downArea = 0.0;
        for(auto &square:squares){
	    double x = square[0], y = square[1], l = square[2];
	    double height_top = 0;
	    double height_bottom = 0;
	    if(y>=split) height_top = l;
	    else if(y+l<=split) height_bottom = l;
	    else if( split <= y+l && split >=y ) height_top = (y+l)-split, height_bottom = split-y;
	    upArea += height_top*l;
	    downArea += height_bottom*l;
	}
	return upArea-downArea;
    }
    /*
     *  time: O(n*log(10^9))
     *  space: O(1)
     * */
    double solve(vector<vector<int> > & squares){
	 int n = squares.size();
         //   s s s s  | s s
	 double lo=0, hi = INT_MAX;
	 while(hi-lo>1e-5){
	    double mid = (lo+hi)/2.0;
	    double val = score(squares, mid);// neg we need to lower mid, otherwise upper mid
	   if( val <= 0 ) hi=mid; //lower mid
	    else lo=mid; //upper mid
	 }
	 return lo;
    }
    double separateSquares(vector<vector<int>>& squares) {
       return solve(squares);	    
    }
};
/*
 *
  max point --> min(rect, y+l)
  min point --> max(rect, y);

     b
   ------    : ----> l
  
   ----b---- : ---->  (y+l) - rect

   ------   :  ----> 0
     b
 *
 * */
