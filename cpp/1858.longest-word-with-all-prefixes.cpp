class Solution {
public:
    class TreeNode{
	    public:
		    unordered_map<char, TreeNode* > to;
		    bool isTerminal = false;
		    TreeNode(){
		    }
    };
    class Trie{
	    TreeNode *root;
	    public:
		    Trie(){
			    this->root = new TreeNode();
		    }
		    void insert(string &st){
			    auto current = root;
			    for(auto letter:st){
				    if(!current->to.count(letter)){
					    current->to[letter] = new TreeNode();
				    }
				    current = current->to[letter];
			    }
			    current->isTerminal = true;
		    }
		    bool hasAllPrefixes(string &word){
			    auto current = root;
			    for(auto letter:word){
				    if(!current->to.count(letter))return false;
				    if(!current->to[letter]->isTerminal)return false;
				    current = current->to[letter];
			    }
			    return true;
		    }
    };
    string solve(vector<string> &words){
	    Trie objTrie;
	    for(auto &word:words){
		    objTrie.insert(word);
	    }
	    int maxLen = 0;
	    string res = "";
	    for(auto &word:words){
		    if(objTrie.hasAllPrefixes(word)){
			    if(word.size() > maxLen){
				    maxLen = word.size();
				    res = word;
			    }else if(word.size() == maxLen && res > word){
				    res = word;
			    }
		    }
	    }
	    return res;
    }
    string solve2(vector<string> &words){
	    sort(words.begin(), words.end());
	    string res = "";
	    unordered_set<string> marked;
	    for(auto &word:words){
		    int m = word.size();
		    if( m == 1 ||
				    marked.count(word.substr(0, m-1))){
			    marked.insert(word);
			    if(word.size() > res.size()){
				    res = word;
			    }else if(word.size() == res.size() && res > word){
				    res = word;
			    }
		    }

	    }
	    return res;
    }
    string longestWord(vector<string>& words) {
	    return solve2(words);
	    return solve(words);
    }
};
