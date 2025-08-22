/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node * solve1(Node *root){
	    if(!root)return NULL;
	    queue<Node *> q;
	    q.push(root);
	    while(!q.empty()){
		    int sz = q.size();
		    Node * prev = NULL;
		    for(int i = 0 ; i < sz; i++){
		          auto current = q.front(); q.pop();
			  if(prev) prev->next = current;
			  if(current->left)q.push(current->left);
			  if(current->right)q.push(current->right);
			  prev = current;
		    }
		    if(prev)prev->next = NULL;
	    }
	    return root;
    }
    Node* connect(Node* root) {
	    return solve1(root);
    }
};
