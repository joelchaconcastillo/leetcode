class Solution {
public:
	//&(|(f))
	//l      r
	// l     r
	//  l
	//      i
	//  .   .
	//  l   r
	//   l  r
	//    l r 
    vector<bool> getExpression(string &st, int l, int r){
	    int i = l+1, cnt = 1, last = l+1;
	    vector<bool> expressions;
	    while(cnt!=0 && i < r){
		if(st[i]== ')')cnt--;
		if(st[i] == '(') cnt++;
		if(st[i] == ',' && cnt == 1 ){
		    expressions.push_back(eval(st, last, i));
		    last = i+1;
		}
		i++;
	    }
	    expressions.push_back(eval(st, last, i-1));
	    return expressions;
    }
    bool eval(string &st, int l, int r){
	 if(st.substr(l, r-l)== "t") return true;
	 if(st.substr(l, r-l)== "f") return false;
	 char operation = st[l];
	 vector<bool> expressions = getExpression(st, l+1, r);
	 bool res = expressions[0];
	 if(operation == '!')res = !expressions[0];
	 for(int i = 1 ; i < expressions.size(); i++){
	     if(operation == '|')res |= expressions[i];
	     if(operation == '&')res &= expressions[i];
	 }
	 return res;
    }
    bool solve(string &st){
	 return eval(st, 0, st.size());
    }
    char evaluate(vector<char> &values, char op){
	 if(op == '!') return values[0]=='t'?'f':'t';
	 bool hasPos = false, hasNeg = false;
	 for(auto val:values){
             if(val == 't') hasPos=true;
	     if(val == 'f') hasNeg=true;
	 }
	 if( op == '&' ){
	       if(hasNeg) return 'f';
	       if(hasPos) return 't';
	 }
	 if( op == '|' ){
	       return hasPos?'t':'f';
	 }
	 return 'f';
    }
    bool solve2(string &s){ // &(|(f))
	 vector<char> st;
	 for(auto i:s){
	    if( i == ',' ) continue;
	    if( i != ')'){
		st.push_back(i);
		continue;
	    }
	    //otherwise it is an ')' bracket!!
            vector<char> values;
	    while(st.back()!='('){
		  values.push_back(st.back());
		  st.pop_back();
	    }
	    st.pop_back();// remove '('
	    char op = st.back();
	    st.pop_back();
	    char res = evaluate(values, op);
	    st.push_back(res);
	 }
	 return st.back()=='t';
    }
    bool solve3(string &s){
	 vector<char> st;
	 for(auto i:s){
	     if( i==',' || i=='(' )continue;
	     else if( i == '!' || i == '|' || i == '&' || i == 'f' || i =='t')st.push_back(i);
	     else if( i == ')'){
		  bool hasT = false, hasF = false;
		  while(st.back()!='!' && st.back() != '&' && st.back() != '|'){
		       if(st.back() == 't') hasT = true;
		       if(st.back() == 'f') hasF = true;
		       st.pop_back();
		  }
		  char op = st.back();
		  st.pop_back();
		  if(op == '!')st.push_back(hasT?'f':'t');
		  else if( op == '&') st.push_back(hasF?'f':'t');
		  else if( op == '|') st.push_back(hasT?'t':'f');
	     }
	 }
	 return st.back()=='t';
    }
    bool parseBoolExpr(string expression) {
	 return solve3(expression);
	 //return solve2(expression);
	 //return solve(expression);
    }
};
/*
 
- Do we always have a operation before brackets?

Example 1:
Input: expression = "&(|(f))"
   "&(|(f))"
       *
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.

Example 2:
Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.

Example 3:
Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

*/
