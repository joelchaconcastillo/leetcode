class Solution {
public:
    /*
     *   time: O(n)
     *   space: O(n)
     * */
    bool hasSameDigits(string s) {
       while(s.size()>2){
	  string tmp="";
	  for(int i = 0 ; i+1<s.size(); i++){
	     tmp+=((s[i]-'0'+s[i+1]-'0')%10)+'0';
	  }
	  s = tmp;
       }
       return s[0]==s[1];
    }
};
