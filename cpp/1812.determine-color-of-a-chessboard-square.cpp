class Solution {
public:
    bool squareIsWhite(string coordinates) {
         int first = coordinates[0]-'a', second = coordinates[1]-'1';
	 if(first%2==0){
		 return second%2!=0;
	 }else{
		 return second%2==0;
	 }
    }
};
