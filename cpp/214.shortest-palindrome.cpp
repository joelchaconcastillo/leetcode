class Solution {
public:
    string solve(string &st){
	  if(st.empty())return "";
	  auto s1 = st;
	  string s2(st.rbegin(), st.rend());
	  string s3 = s1+"#"+s2;
	  int n = s3.size();
	  int j = 0;
	  vector<int> prefix(n, 0);
	  for(int i = 1; i < n ; i++){
	       j = prefix[i-1];
	       while(j>0 && s3[j] != s3[i]) j = prefix[j-1];
	       if(s3[i]==s3[j])j++;
	       prefix[i] = j;
	  }
	  string missing = st.substr(prefix.back());
	  reverse(missing.begin(), missing.end());
	  return missing+st;
    }
    string solve2(string &st){
	    long long hashBase = 29;
	    long long modValue = 1e9+7;
	    long long forward = 0, backward=0, power=1;
	    int palindromeIndex = -1, n = st.size();
	    for(int i = 0 ; i < n; i++){
		   char current = st[i];
		   forward = (forward*hashBase+(current-'a'+1))%modValue;
		   backward = (backward+(current-'a'+1)*power)%modValue;
		   power = (power*hashBase)%modValue;
		   if(forward == backward) palindromeIndex = i;
	    }
	    string suffix  = st.substr(palindromeIndex+1);
	    string reverse_(suffix.rbegin(), suffix.rend());
	    return reverse_+st;
    }
    string shortestPalindrome(string s) {
	    return solve2(s);
	    return solve(s);
    }
};
/*
  aacecaaa

  aacecaaa  aaacecaa
  01000011  11123456

  abcd   dcba
  0000   0000

     aabba   abbaa
     01001   23456
 * */
