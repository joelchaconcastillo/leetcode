class Solution {
public:
    string makeFancyString(string s) {
          string res = "";
	  char prev = '.';
	  int cont = 0;
	  for(auto i:s){
		  if(i!=prev){
			  cont = 1;
		  }else{
			  cont++;
		  }
		  if(cont < 3)res +=i;
		  prev = i;
	  }
	  return res;
    }
};
