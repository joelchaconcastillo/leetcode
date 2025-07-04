/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node * solve(Node *root, Node *leaf){
	    Node *prev = NULL, *current = leaf, *next = leaf->parent;
	    while(current){
		    if(current->left && next) current->right = current->left;
		    if(next) current->left = next;
		    if(next && next->left == current) next->left = NULL;
		    if(next && next->right == current) next->right = NULL;
		    current->parent = prev;
		    prev = current;
		    current=next;
		    if(next) next = next->parent;
	    }
	    return leaf;
    }
    Node * solve2(Node *root, Node *leaf){
	    Node *prev = NULL, *current = leaf;//current->7
	    while(current){//current = 7
		  auto left = current->left;//left = NULL
		  auto parent = current->parent; // parent = 2
		  if(prev != left) current->right = left;
	  current->parent = prev;
		  current->left = parent; // 
		  prev = current;
		  current = parent;
	    }
	    return leaf;
    }
    Node* flipBinaryTree(Node* root, Node * leaf) {
	    return solve2(root, leaf);
//	    return solve(root, leaf);
    }
};
