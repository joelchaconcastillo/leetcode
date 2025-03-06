class Solution {
public:
   /*
       time: O(n)
       space: O(n)
       elapsed time to solve: 7 min.
    * */
    bool solve(string &st){
	 int n = st.size();
	 string _stack="";
	 map<char, char> matching_bracket = {
		{']','['}, {')','('},
		{'}','{'}
	 };
	 for(auto i:st){
	    if(!_stack.empty()){
	       if(_stack.back() == matching_bracket[i])
	       _stack.pop_back();
	       else _stack.push_back(i);
	    }else _stack.push_back(i);
	 }
	 return _stack.empty();
    }
    bool isValid(string s) {
	 return solve(s);
    }
};
