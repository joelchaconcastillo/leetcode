class Solution {
public:
    string largestGoodInteger(string num) {
           string res = "";	    
	   for(int i = 2; i < num.size(); i++){
		   if(num[i-2] == num[i] && num[i-1] == num[i]){
			   res = max(res, string(3,num[i]));
		   }
	   }
	   return res;
    }
};
