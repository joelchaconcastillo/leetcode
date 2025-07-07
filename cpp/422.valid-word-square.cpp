class Solution {
public:
    bool solve(vector<string> &words){
	    int n = words.size(), maxN=0;
	    for(auto &word:words){
		    maxN = max((int)word.size(), maxN);
	    }
	    for(auto &word:words){
		    while(word.size() < maxN)word+=" ";
	    }
	    int i = 0;
	    while( i < n && i < words[i].size()){
		  string word1="", word2 = words[i].substr(i);
		  for(int j = i; j < n; j++) word1 += words[j][i];
		  if(word1 != word2)return false;
		  i++;
	    }
	    return true;
    }
    bool validWordSquare(vector<string>& words) {
	    return solve(words);
    }
};
