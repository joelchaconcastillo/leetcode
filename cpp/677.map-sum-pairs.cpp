class TreeNode_{
	public:
		unordered_map<char, TreeNode_*> _to;
		int totalScore = 0;
		TreeNode_(){
		}
};
class MapSum {
public:
    unordered_map<string, int> values;
    TreeNode_ *root;
    MapSum() {
        root = new TreeNode_();
    }
    void insert(string key, int val) {
	    auto current =  root;
	    for(auto letter:key){
		    if(!current->_to.count(letter))
		    current->_to[letter] = new TreeNode_();
		    current->_to[letter]->totalScore += val-values[key];
		    current = current->_to[letter];
	    }
	    values[key] = val;
    }
    
    int sum(string prefix) {
	    auto current = root;
	    for(auto letter:prefix){
		    if(!current->_to.count(letter)) return 0;
		    current = current->_to[letter];
	    }
	    return current->totalScore;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
