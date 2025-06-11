class Solution {
public:
    void result(string &st){
	   int eval=0;
	   string current = "";
	   while(!st.empty() && st.back()!='(') current+=st.back(), st.pop_back();
	   st.pop_back();
	   reverse(current.begin(), current.end());
	   int total=0;
	   string simplified="";
	   int negcount = 0, i =0;
           while(i<current.size()){
		     negcount=0;
		     while(i < current.size() && (current[i]=='-' || current[i] == '+')){
			   if(current[i] == '-')negcount++;
			   i++;
		     }
		     simplified="";
		     while(i < current.size() && isdigit(current[i])){
			simplified+=current[i];
			i++;
		     }
		     if(negcount%2==0) total += stoll(simplified);
		     else total -= stoll(simplified);
	   }
	   st+=to_string(total);
    }
    int solve(string &st){
	st = "("+st+")";
	//remove all spaces..
	string tmp = "";
	for(auto letter:st) if(letter!=' ')tmp+=letter;
	st = tmp;
	string _stack="";
	for(auto letter:st){
	    if(letter == ')'){
		 result(_stack);
	    }else{
	      _stack += letter;
	    }
	}
	return stol(_stack);
    }
    int eval(string &s, int &i){
        long long result = 0, num = 0;
	int sign = 1;
	while(i < s.size()){
	      char c = s[i];
	      if(isdigit(c)){
		 num=0;
		 while(i < s.size() && isdigit(s[i])){
		    num *=10;
		    num += s[i]-'0';
		    i++;
		 }
		 result += sign*num;
		 continue;
	      }
	      if(c==' '){
		      i++;
	      }
	      else if(c=='+'){
		      i++;
		      sign=1;
	      }
	      else if(c=='-'){
		      i++;
		      sign=-1;
	      }
	      else if(c=='('){
		      i++;
		      result += sign*eval(s, i);
	      }
	      else if(c==')'){
		      i++;
		      return result;
	      }else{
	         i++;
	      }
	}
	return result;
    }
    int solve2(string &s){
	int index = 0;
	return eval(s, index);
    }
    int calculate(string s) {
	return solve2(s);
	return solve(s);
    }
};
