class Solution {
public:
    string maximumOddBinaryNumber(string s) {
       int cont=0;
       for(auto bit:s) cont+= bit=='1';
       string res(s.size(),'0');
       if(cont>0)res.back()='1';
       cont--;
       int idx=0;
       while(cont){
	       res[idx++]='1';
	       cont--;
       }
       return res;
    }
};
