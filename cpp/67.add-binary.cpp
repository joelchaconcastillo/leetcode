class Solution {
public:
	/*
	 *  time: O(n+m)
	 *  space: O(n+m)
	 * */
    string solve(string &a, string &b){
	string res = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int n = a.size(), m = b.size(), rem=0;
	for(int i = 0 ;i < max(n, m); i++){
	   int digit_a = (i<n)?a[i]-'0':0;
	   int digit_b = (i<m)?b[i]-'0':0;
	   int sum = digit_a+digit_b+rem;
	   if(sum==1) res+="1", rem=0;
	   else if(sum==0) res+="0", rem=0;
	   else if(sum==2) res+="0", rem=1;
	   else if(sum==3) res+="1", rem=1;
	}
	if(rem)res+="1";
	reverse(res.begin(), res.end());
	return res;
    }
    string addBinary(string a, string b) {
       return solve(a, b);	    
    }
};
/*
 *     sum \in [0, 3]
 *     0 + 00 --> 0
 *     0 + 1 --> 1
 *     1 + 0 --> 1
 *     1 + 1 --> 1 : rem 1
 * */
