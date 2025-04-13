class Solution {
public:
    int solve(string &s){
	unordered_map<char, int> freq;
	for(auto i:s)freq[i]++;
	int res = -1;
	int n = s.size();
	for(int i = 0 ; i <n; i++){
	   if(freq[s[i]]==1){
	     res = i;
	     break;
	   }
	}
	return res;
    }
    int firstUniqChar(string s) {
	return solve(s);
    }
};
