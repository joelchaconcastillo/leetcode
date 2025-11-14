class Solution {
public:
    // "ab"↩ "aa"
    //   i
    //         j
    bool helper(string &pattern, string &st, int i, int j, unordered_map<char, string> &p2s, unordered_set<string> &marked){
	 if(i==pattern.size() && j==st.size())return true;
	 if(p2s.count(pattern[i])){
		 auto word = p2s[pattern[i]];
		 if( st.substr(j, word.size()) != word)return false;
		 return helper(pattern, st, i+1, j+word.size(), p2s, marked);
	 }
	 bool res = false;
	 string current = "";
	 for(int jj = j; jj < st.size(); jj++){
		 current += st[jj];
		 if(marked.count(current))continue;
		 marked.insert(current);
		 p2s[pattern[i]] = current;
		 if(helper(pattern, st, i+1, jj+1, p2s, marked))return true;
		 p2s.erase(pattern[i]);
		 marked.erase(current);
	 }
	 return res;
    }
    bool solve(string &pattern, string &st){
	 unordered_map<char, string> p2s;
	 unordered_set<string> marked;
	 return helper(pattern, st, 0, 0, p2s, marked);
    }
    bool wordPatternMatch(string pattern, string s) {
	 return solve(pattern, s);
    }
};
