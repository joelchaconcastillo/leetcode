class TrieNode{
   public:
      unordered_map<char, TrieNode *> links;
      int countTerminal = 0;
      int countPrefix = 0;
      TrieNode(){}
};
class Trie {
public:
    TrieNode *root; 
    Trie() {
	  root = new TrieNode();
    }
    
    void insert(string word) {
	    auto current = root;
	    for(auto letter:word){
		    if(!current->links.count(letter))
			    current->links[letter] = new TrieNode();
		    current = current->links[letter];
		    current->countPrefix++;
	    }
	    current->countTerminal++;//check it as terminal
    }
    
    int countWordsEqualTo(string word) {
	    auto current = root;
	    for(auto letter:word){
		    if(!current->links.count(letter)) return 0;
		    current = current->links[letter];
	    }
	    return current->countTerminal;
    }
    
    int countWordsStartingWith(string prefix) {
            auto current = root;
	    for(auto letter:prefix){
		    if(!current->links.count(letter)) return 0;
		    current = current->links[letter];
	    }
	    return current->countPrefix;
    }
    
    void erase(string word) {
	    int count_words = this->countWordsEqualTo(word);
	    if(count_words == 0)return;
	    auto current = root;
	    for(auto letter:word){
		    auto next = current->links[letter];
		    if(--(current->links[letter]->countPrefix)==0){
			    current->links.erase(letter);
		    }
		    current = next;
	    }
	    current->countTerminal--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
