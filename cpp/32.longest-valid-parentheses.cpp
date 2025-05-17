class Solution {
public:
    int solve(string &s){
	s = "))"+s;
	int n = s.size();
	vector<pair<int, int> > st;
	for(int i = 0 ; i < n; i++){
	   if(!st.empty() && s[st.back().first] == '(' && s[i] == ')'){
	       int score = st.back().second+1;
	       st.pop_back();
	       st.back().second +=score;
	   }else st.push_back({i, 0});
	}
	int res = 0 ;
	for(auto ii:st)res = max(res, ii.second);
	return 2*res;
    }
    int longestValidParentheses(string s) {
	    return solve(s);
    }
};
/*
     )(

     )  (  )  (  )  ) 
     
     )        ()

  ( ) ) ( ( ( ) )
      i

 l                             r
 ( ( (    (  ) ( ( ) )   
 1 2 3    4  3 4 5 4 3
 * */
