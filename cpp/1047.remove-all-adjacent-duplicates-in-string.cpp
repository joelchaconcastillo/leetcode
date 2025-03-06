class Solution {
public:
   /*
       time: O(n)
       space: O(n) // to store res
       elapsed time to resolve: 3 min.
    * */
    string solve(string &s){
        string res = "";
	for(auto i:s){
	    if(!res.empty() && i == res.back()){
	       res.pop_back();
	    }else{
	       res+=i;
	    }
	}
	return res;
    }
    string removeDuplicates(string s) {
       return solve(s);	    
    }
};
