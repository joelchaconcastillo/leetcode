class Solution {
public:
    void combinations(vector<string> &options, int pos, string &current, vector<string> &res, string &digits){
	 if(pos == digits.size()){
		 if(current.empty())return ;
		 res.push_back(current);
		 return;
	 }
	 for(auto letter:options[digits[pos]-'0']){
	      current.push_back(letter);
	      combinations(options, pos+1, current, res, digits);
	      current.pop_back();
	 }
    }
    vector<string> solve(string &digits){
	  vector<string> options(11);
	  int pos = 0;
	  options[2] = {"abc"};
	  options[3] = {"def"};
	  options[4] = {"ghi"};
	  options[5] = {"jkl"};
	  options[6] = {"mno"};
	  options[7] = {"pqrs"};
	  options[8] = {"tuv"};
	  options[9] = {"wxyz"};
	  vector<string> res;
	  string current = "";
	  combinations(options, 0, current, res, digits);
	  return res;
    }
    vector<string> letterCombinations(string digits) {
	    return solve(digits);
    }
};
