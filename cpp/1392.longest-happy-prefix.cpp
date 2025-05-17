class Solution {
public:
    string solve2(string &s){
	 int n = s.size();
	 long long h1a = 0, h2a = 0, h1b = 0, h2b = 0, mul1 = 1, mul2 = 1, len = 0;
	 const long long mod1 = 1e9+7, mod = 1e9+9;
	  for(int i = 0, j = s.size()-1; j > 0; i++,j--){
		  int first = s[i]-'a', last = s[j]-'a';
		  h1a = (h1a*26+first)%mod;
		  h2a = (h2a+mul1*last)%mod;
		  mul1 = (mul1*26)%mod;
		  h1b = (h1b*26+first)%mod;
		  h2b = (h2b+mul2*last)%mod;
		  mul2 = (mul2*26)%mod;

		  if(h1a == h2a && h1b == h2b)len=i+1;
	  }
	  return s.substr(0, len);
    }
    string solve1(string &s){
	 int n = s.size();
	 vector<int> pi(n);
	 for(int i = 1, j = 0; i < n; i++){
	     while(j > 0 && s[i] != s[j])
		     j = pi[j-1];
	     if(s[i] == s[j])j++;
	     pi[i] = j;
	 }
	 return s.substr(0, pi.back());
    }
    string longestPrefix(string s) {
	   return solve2(s);
	   //return solve1(s);
    }
};
