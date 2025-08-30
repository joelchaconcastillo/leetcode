class Solution {
public:
    int maxPower(string s) {
       int res =0;
       int cont =0; char prev = 0;
       for(auto i:s){
	       if(i!=prev)cont=1;
	       else cont++;
	       res = max(cont, res);
	       prev = i;
       }
       return res; 
    }
};
