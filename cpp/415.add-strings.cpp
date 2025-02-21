class Solution {
public:
    string solve(string &num1, string &num2){
	 int n = num1.size(), m = num2.size();
	 reverse(num1.begin(), num1.end());
	 reverse(num2.begin(), num2.end());
	 string total = "";
	 int rem = 0;
	 for(int i = 0; i < max(n, m); i++){
	     int A = (i<n)?num1[i]-'0':0;
	     int B = (i<m)?num2[i]-'0':0;
	     int sum = A+B+rem;
	     rem = sum/10;
	     total += to_string(sum%10);
	 }
	 if(rem) total+=to_string(rem);
	 reverse(total.begin(), total.end());
	 return total;
    }
    string addStrings(string num1, string num2) {
       return solve(num1, num2);	    
    }
};
/*
   i
  99
 199
  18
  81
 sum = a_i+b_i+rem;
 rem = sum/10;
 sum %=10;
 total += sum

 * */
