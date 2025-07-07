/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* current, unordered_map<int, pair<Node*, Node*>> &new_nodes){
	    if(new_nodes.count(current->val)) return;
	    new_nodes[current->val] = {new Node(current->val), current};
	    for(auto _to:current->neighbors){
		    dfs(_to, new_nodes);
	    }
    }
    Node* cloneGraph(Node* node) {
	    if(!node)return node;
	    unordered_map<int, pair<Node*, Node*> > new_nodes;
	    dfs(node, new_nodes);
	    for(auto &[val, pp_new_source]:new_nodes){
		    for(auto _to:pp_new_source.second->neighbors){
			    pp_new_source.first->neighbors.push_back(new_nodes[_to->val].first);
		    }
	    }
	    return new_nodes[node->val].first;
    }
};
