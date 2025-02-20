class Solution {
public:
    bool solve(vector<string> &words, string &order){
	  int n = words.size(), m = order.size();
	  unordered_map<char, int> char_to_index;
	  for(int i = 0 ; i < m; i++) char_to_index[order[i]]=i;
	  for(auto &word:words){
	      for(auto &letter:word){
		   letter = char_to_index[letter]+'0';
	      }
	  }
	  auto copy = words;
	  sort(copy.begin(), copy.end());
	  for(int i = 0 ; i < n; i++){
	      if(copy!=words)return false;
	  }
	  return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
	 return solve(words, order);
    }
};
