class Solution {
public:
	// 2x +4 -8x+3-5x
    pair<int, int> evaluateSide(string st){
	    string current = "";
	    if(st.front()!='-' && st.front() != '+')st = "+"+st;
	    int X=0, C=0, sign=1;
	    for(int j = st.size()-1; j >=0; j--){
	            char i = st[j];
		    if(i == '+' || i == '-'){
			    if(i=='-')sign = -1;
			    else sign=1;
			    if(current.back()=='x'){
				    current.pop_back();
				    if(current.empty()) X+= sign;
				    else X += sign*stoll(current);
			    }else{
				    C += sign*stoll(current);
			    }
			    current = "";
		    }else current = i+current;
	    }
	    return {X, C};
    }
    string solveEquation(string equation) {
	  int idx = 0, n = equation.size();
	  while(idx < n && equation[idx]!='=') idx++;
	  pair<int, int> exs_num = evaluateSide(equation.substr(0, idx));
	  auto minus_exs_num = evaluateSide(equation.substr(idx+1, n-idx-1));
	  exs_num.first -= minus_exs_num.first;
	  exs_num.second -= minus_exs_num.second;
	  if(exs_num.first == 0 && exs_num.second == 0)return "Infinite solutions";
	  if(exs_num.first == 0 && exs_num.second!=0)return "No solution";
	  return "x="+to_string(-(exs_num.second/exs_num.first));
    }
};
