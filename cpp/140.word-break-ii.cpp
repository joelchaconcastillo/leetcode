class Solution {
public:
    void back_tracking(string &s, vector<string> &wordDict, int idx, vector<string> &res, vector<string> &current){
	 if( idx > s.size()) return; //prune 1
	 if(idx == s.size()){
		string tmp = "";
		for(int i = 0 ; i < current.size() ;i++){
		   tmp += current[i];
		   if(i+1<current.size()) tmp+=" ";
		}
		res.push_back(tmp);
		return;
	 }
	 for(auto &word:wordDict){
	    if(s.substr(idx, word.size()) != word)continue;
	    current.push_back(word);
	    back_tracking(s, wordDict, idx+word.size(), res, current);
	    current.pop_back();
	 }
    } 
    vector<string> solve1(string &s, vector<string> &wordDict){
	  vector<string> res, current;
	  back_tracking(s, wordDict, 0, res, current);
	  return res;
    }
    unordered_map<string, vector<string> > memo;
    vector<string> dp(string &rem, unordered_set<string> &wordSet){
	  if(memo.count(rem))return memo[rem];
	  if(rem.empty())return {};
	  vector<string> res;
	  for(int i = 1; i <= rem.size(); i++){
		  string sub_word= rem.substr(0, i);
		  if(wordSet.count(sub_word)==0)continue;
		  for(auto &next_word:dp(sub_word, wordSet)){
		     res.push_back(next_word+(next_word.empty()?"":" ")+next_word); 
		  }

	  }
	  return memo[rem] = res;
    }
    vector<string> solve2(string &s, vector<string> &wordDict){
	    memo.clear();
	    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
	    return dp(s, wordSet);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
	  return solve1(s, wordDict);
    }
};
