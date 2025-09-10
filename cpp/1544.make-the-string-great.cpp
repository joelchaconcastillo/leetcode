class Solution {
public:
    string makeGood(string s) {
         string st;
         for(auto letter:s){
		 if(!st.empty() && 
				 tolower(st.back())==tolower(letter) && 
				 ((isupper(letter) && islower(st.back()) ) 
				   || (isupper(st.back()) && islower(letter) )  )) 
				 st.pop_back();
		 else
		 st.push_back(letter);
	 }	 
	 return st;
    }
};
