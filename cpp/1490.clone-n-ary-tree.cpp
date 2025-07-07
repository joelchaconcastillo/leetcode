/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node * dfs(Node *current, unordered_map<Node*, Node*> &source_new_dict){
	    if(!current) return NULL;
	    if(source_new_dict.count(current))return source_new_dict[current]; //already visited so we return the same node // BASE CASE!!
	    Node *new_node = new Node(current->val);
	    source_new_dict[current] = new_node;
	    for(auto next:current->children){
		    new_node->children.push_back(
				       dfs(next, source_new_dict)
				    );
	    }
	    return new_node;
    }
    Node * dfs2(Node *current){
	    if(!current) return NULL;
	    Node * res = new Node(current->val);
	    for(auto Next:current->children){
		    res->children.push_back(dfs2(Next));
	    }
	    return res;
    }
    Node * solve2(Node *root){
	    return dfs2(root);
    }
    Node * solve(Node *root){
	    unordered_map<Node *, Node *> source_new_dict;
	    return dfs(root, source_new_dict);
    }
    Node* cloneTree(Node* root) {
	    return solve2(root);
	    return solve(root);
    }
};
