class Node{
public:
   unordered_map<char, Node *> _next;
   char label='0';
   bool isTerminal=false;
   Node(){
   }
   Node(char label, bool isTerminal){
      this->label = label;
      this->isTerminal = isTerminal;
   }
};
class Trie {
public:
    Node *root;
    Trie() {
	root = new Node('0', false);
    }
    void insert(string word) {
	 Node *current = root;
	 for(auto i:word){
	     if(!current->_next.count(i)){
		     current->_next[i] = new Node(i, false);
	     }
	     current = current->_next[i];
	 }
	 current->isTerminal = true;
    }
    
    bool search(string word) {
	 Node *current = root;
	 for(auto i : word){
	    if(current->_next.count(i)) current = current->_next[i];
	    else return false;
	 }
	 return current->isTerminal;
    }
    
    bool startsWith(string prefix) {
	 Node * current = root;
	 for(auto i : prefix){
	    if(current->_next.count(i)) current = current->_next[i];
	    else return false;
	 }
	 return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
