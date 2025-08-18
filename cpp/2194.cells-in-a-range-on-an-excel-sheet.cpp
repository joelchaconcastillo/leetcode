class Solution {
public:
    vector<string> cellsInRange(string s) {
       vector<string> res;
       for(char col = s[0]; col<=s[3]; col++){
	       for(char row = s[1]; row <= s[4];row++){
		       res.push_back(""+string(1,col)+string(1,row));
	       }
       }	       
       return res;
    }
};
