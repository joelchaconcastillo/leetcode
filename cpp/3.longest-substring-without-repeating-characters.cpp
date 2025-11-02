class Solution {
public:
    int solve(string &s){
	unordered_map<char, int> freq;
	int l = 0, n = s.size(), res = 0;
	for(int i = 0 ; i <n ;i++){
	     freq[s[i]]++;
	     while(freq[s[i]]>1) --freq[s[l++]];
	     res = max( res, i-l+1);
	}
	return res;
    }
    int lengthOfLongestSubstring(string s) {
       return solve(s);	    
    }
};
