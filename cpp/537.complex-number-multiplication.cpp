class Solution {
public:
    long long get_real(string &st){
	    string res = "";
	    int i = 0;
	    while(i < st.size() && st[i]!='+') res+=st[i++];
	    return stoll(res);
    }
    long long get_complex(string &st){
	    string res = "";
	    int i = 0;
	    while(i < st.size() && st[i]!='+') i++;
	    i++;
	    while(i<st.size() && st[i]!='i') res+=st[i++];
	    return stoll(res);
    }
    string complexNumberMultiply(string num1, string num2) {
        long long a = get_real(num1), b =get_complex(num1), c=get_real(num2), d=get_complex(num2);	    
	string res = "";// (a+b)*(c+d) ---> (a*c) + (a*d) + (b*c) + (b*d)
	res += to_string((a*c)-(b*d));
	res += "+"+to_string((a*d)+(b*c))+"i";
	return res;
    }
};
