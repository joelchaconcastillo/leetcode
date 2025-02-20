class Solution {
public:
    string forwardSolve(string &s){
       string res = "";
       int cont = 0;
       for(auto let:s){
	  if(let=='(')cont++;
	  else if( let == ')')cont--;
	  if(cont>=0)res+=let;
	  else cont=0;
       }
       return res;
    }
     string backwardSolve(string &s){
       string res = "";
       int cont = 0;
       for(auto it=s.rbegin(); it != s.rend(); it++){
	  auto let = *it;
	  if(let=='(')cont--;
	  else if( let == ')')cont++;
	  if(cont>=0)res+=let;
	  else cont=0;
       }
       reverse(res.begin(), res.end());
       return res;
    }
    string minRemoveToMakeValid(string s) {
	    auto res = forwardSolve(s);
	    return backwardSolve(res);
    }
};
/*

  a  )  b  (  c  )  d
  0  -1 -1 0  0 -1  0
  0  0  0  1  0  0  0 
  a  x  b  (  c  )  d

  a ( ( ( ( )
  0 1 2 3 4 3
  a -1 -1 -1 0 1

 * */
