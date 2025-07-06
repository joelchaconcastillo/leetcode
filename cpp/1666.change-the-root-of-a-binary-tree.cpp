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
		    if(current->left && next) current->right = current->left;//check that prev node is a left branch, if it is the case then point the right one to it
		    if(next) current->left = next; //redirect left branch to parent "re-parent"
		    //next two lines will clean the tree a it is being processed
		    if(next && next->left == current) next->left = NULL; //if this is the left branch then redirect left, in this way we avoid loops
		    if(next && next->right == current) next->right = NULL;//the same the before but in this case next will be a right 
		    current->parent = prev;//reparent it
		    prev = current;
		    current=next;
		    if(next) next = next->parent;//update next only if current is not the root
	    }
	    return leaf;
    }
    Node * solve2(Node *root, Node *leaf){
	    Node *prev = NULL, *current = leaf;
	    while(current){
	          if(current->left && current->parent)current->right = current->left;//make sure that it is an intermediate node
		  auto left = current->left;
		  auto parent = current->parent; // 
		  if(current->parent && current->parent->left == current) current->parent->left = NULL;
		  if(current->parent && current->parent->right == current) current->parent->right = NULL;
	  current->parent = prev;
		  current->left = parent; // 
		  prev = current;
		  current = parent;
	    }
	    return leaf;
    }
    Node* flipBinaryTree(Node* root, Node * leaf) {
	    return solve(root, leaf);
    }
};
