class Solution {
public:
    string KMP(string st){ 
	    int n = st.size();
	    vector<int> prefix(n,0);
	    int j = 0;
	    for(int i = 1; i <n; i++){
		    j = prefix[i-1];
		    while(j>0 && st[i]!=st[j]) j = prefix[j-1];
		    if(st[i]==st[j])j++;
		    prefix[i]=j;
	    }
	    int max_prefix= *max_element(prefix.begin(), prefix.end());
	    return st.substr(0, max_prefix);
    }
    // TLE
    string solve(string &st){
	   int n = st.size();
	   string res = "";
	   for(int i = 0 ; i < n; i++){
		   auto longest_prefix = KMP(st.substr(i));
		   if(res.size() < longest_prefix.size()) res = longest_prefix;
	   }
	   return res;
    }
    long long mod = 1e9+7;
    long long base = 29;
    string _search(string &st, int len){
	    int n = st.size();
	    long long hash = 0, power = 1;
	    for(int i = 0; i < len; i++){
		    hash = (hash*base+st[i])%mod;
		    if(i+1!=len)power = (power*base)%mod;
	    }
	    unordered_map<long long, vector<int> > hashTable;
	    hashTable[hash].push_back(0);
	    for(int i = len; i < n; i++){
		    hash = (hash-st[i-len]*power %mod+mod) %mod;
		    hash = (hash*base+st[i])%mod;
		    if(hashTable.find(hash) != hashTable.end()){
			    for(int start:hashTable[hash]){
				    if(st.substr(start, len) == st.substr(i-len+1, len))
					    return st.substr(start, len);
			    }
		    }
		    hashTable[hash].push_back(i-len+1);
	    }
	    return "";

    }
    string solve_optimized(string &st){
	    int lo = 0, hi = st.size();
	    string res = "";
	    while(lo<hi){
		    int m = (lo+hi)/2;
		    auto repeated = _search(st, m);
		    if(repeated.size() > res.size()) res = repeated;
		    if(repeated.empty()){// lo ----m-lo(2)---- hi
			 hi = m;
		    }else{
			 lo = m+1;
		    }
	    }
	   return res;
    }
    string longestDupSubstring(string s) {
	    return solve_optimized(s);
	    return solve(s);
        
    }
};
/*
 
  Input: s = "banana"
  anana
  00123
  nana
  0012
  ana
  001
  na
  00
  a
  0
  Output: "ana"

 * */
