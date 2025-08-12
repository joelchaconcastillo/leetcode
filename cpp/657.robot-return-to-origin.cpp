class Solution {
public:
    bool judgeCircle(string moves) {
	 int col=0,row=0;
         for(auto move:moves){
		 if(move=='U')row++;
		 else if(move=='D')row--;
		 if(move=='L')col--;
		 else if(move=='R')col++;
	 }		 
	 return col==0 && row==0;
    }
};
