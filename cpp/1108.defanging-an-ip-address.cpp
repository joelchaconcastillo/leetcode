class Solution {
public:
    string defangIPaddr(string address) {
       string res = "";	    
       for(auto i:address){
	       if(i == '.'){
		       res+="[";
		       res+=i;
		       res+="]";
	       }
	       else res+=i;
       }
       return res;
    }
};
