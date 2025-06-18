class Solution {
public:
    int solve(string &st1, string &st2){
	   unordered_map<char, int> pos;
	   for(int i = 0 ; i < st1.size(); i++){
		   pos[st1[i]]=i;
	   }
	   int res = 0, prev=0;
	   for(auto letter:st2){
		   res += abs(prev-pos[letter]);
		   prev = pos[letter];
	   }
	   return res;
    }
    int calculateTime(string keyboard, string word) {
	    return solve(keyboard, word);
    }
};
