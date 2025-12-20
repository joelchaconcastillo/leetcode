class Solution {
public:
    //
    //  f(l, r) = min(
    //                  s[0:l]*(s[l]+s[l:r])*s[r:n])
    //             f(l-1,r), f(l, r+1)
    // AA  +   BB
    //     n1
    // (AA+BB)
    // (AA+B)B
    // A(A+BB)
    // A(A+B)B
    // A A + B B
    //   l   r

    string solve(string expression) {        
	    int n = expression.size();
	    int l = 0;
	    while(l < n && expression[l+1]!='+')l++;
	    int r = l+2;
	    long long res = INT_MAX;
	    string res_str="";
	    for(int i = l ; i >=0; i--){
		    for(int j = r; j < n; j++){
			    string new_expression = expression.substr(0, i)
				    + "("
				    + expression.substr(i, l-i+1)
				    + "+"
				    + expression.substr(r, j-r+1)
				    + ")"
				    + expression.substr(j+1);
			    long long A = 1, B = 1;
			    if(i>0) A = stol(expression.substr(0,i));
			    if(j+1<n) B = stol(expression.substr(j+1));

			    long long eval = 
				    A
				    *
				    (stol(expression.substr(i, l-i+1))
					  +stol(expression.substr(r, j-r+1))
				    )
				    *B;
			    if(res > eval){
			       res_str  = new_expression;
			       res = eval;
			    }else if(res == eval) res_str = min(new_expression, res_str);

		    }
	    }
	    return res_str;
    }
    string minimizeResult(string expression) {        
	    return solve(expression);
    }
};
