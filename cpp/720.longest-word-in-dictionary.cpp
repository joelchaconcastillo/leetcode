class Solution {
public:
    string solve(vector<string>& words) {
	    unordered_set<string> records;
	    for(auto word:words){
		    records.insert(word);
	    }
	    string res = "";
	    for(auto word:words){
		    string current = "";
		    for(auto letter:word){
			    current +=letter;
			    if(records.count(current)){
				    if(res.size() < current.size()){
					    res = current;
				    }else if(res.size() == current.size()){
					    res = min(res, current);
				    }
			    }else break;
		    }
	    }
	    return res;
    }
    class Node{
	    public:
		    unordered_map<char, Node*> _to;
		    string prefix;
		    bool isTerminal = false;
		    Node(string &prefix):prefix(prefix){
		    }
    };
    Node* root;
    void insert(string &word){
	    auto current = root;
	    string prefix = "";
	    for(auto letter:word){
		    prefix += letter;
		    if(!current->_to.count(letter)){
			    current->_to[letter] = new Node(prefix);
		    }
		    current = current->_to[letter];
	    }
	    current->isTerminal=true;
    }
    void insert_words(vector<string> &words){
	    string prefix = "";
	    root = new Node(prefix);
	    for(auto word:words){
		    insert(word);
	    }
    }
    void dfs(Node* current, string &res){
	    if( current->prefix.size() > res.size()){
		    res = current->prefix;
	    }else if(current->prefix.size() == res.size()){
		    res =  min(res, current->prefix);
	    }
	    for(auto [letter, next]:current->_to){
		    if(!next->isTerminal)continue;
		    dfs(next, res);
	    }
    }
    string solve2(vector<string>& words) {
	    insert_words(words);
	    string res = "";
	    dfs(root, res);
	    return res;
    }
    string longestWord(vector<string>& words) {
	    return solve2(words);
	    return solve(words);
    }
};
