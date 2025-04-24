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

    int solve(Node *current){
	    if(!current) return 0;
	    int res = 0;
	    for(auto _next:current->children){
		 if(_next) res = max(res, solve(_next));
	    }
	    return res+1;
    }
    int maxDepth(Node* root) {
	return solve(root);
    }
};
