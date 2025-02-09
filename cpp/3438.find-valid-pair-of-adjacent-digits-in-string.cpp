class Solution {
public:
    string findValidPair(string s) {
       unordered_map<char, int> cnt;
       for(auto i:s)cnt[i]++;
       for(int i = 0; i+1<s.size(); i++){
	   if(s[i]==s[i+1])continue;
	   if( (s[i]-'0') == cnt[s[i]] && (s[i+1]-'0') == cnt[s[i+1]]) return s.substr(i,1)+s.substr(i+1,1);
       }
       return "";
    }
};
