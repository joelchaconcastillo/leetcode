class ValidWordAbbr {
public:
    unordered_set<string> marked_abb, marked_word, banned_abbs;
    string ab(string &st){
	    string res = "";
	    int n = st.size();
	    if(n<=2)return st;
	    return res + st.front()+to_string(n-2)+st.back();
    }
    ValidWordAbbr(vector<string>& dictionary) {
	    unordered_map<string, unordered_set<string>>visited;
	    for(auto &word:dictionary){
		    visited[ab(word)].insert(word);
	    }
	    for(auto [abb, words]:visited){
		    if(words.size() > 1){
			    banned_abbs.insert(abb);
			    continue;
		    }
		    marked_word.insert(*words.begin());
		    marked_abb.insert(abb);
	    }
    }
    
    bool isUnique(string word) {
	 if(!marked_abb.count(ab(word)) 
			 && !banned_abbs.count(ab(word)))return true;
	 return marked_abb.count(ab(word)) && marked_word.count(word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
