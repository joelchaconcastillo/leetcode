class Solution {
public:
    string to_bin(int num){
	 string res="";
	 while(num){
	      res+=(num&1)?"1":"0";
	      num >>=1;
	 }
	 reverse(res.begin(), res.end());
	 return res;
    }
    string solve(string &date){
	 int year=stoi(date.substr(0, 4)), month=stoi(date.substr(5,2)), day=stoi(date.substr(8,2));
	 return to_bin(year)+"-"+to_bin(month)+"-"+to_bin(day);
    }
    string convertDateToBinary(string date) {
	   return solve(date);
    }
};
