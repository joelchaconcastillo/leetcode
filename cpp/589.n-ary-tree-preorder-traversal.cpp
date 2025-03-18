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
    vector<int> solve_iterativelly(Node *root){
	 if(!root)return {};
	 vector<Node *> st;
	 vector<int >res;
	 st.push_back(root);
	 while(!st.empty()){
	      auto current = st.back();
	      st.pop_back();
	      res.push_back(current->val);
	      for(int i  = current->children.size()-1; i >= 0; i--){
		  st.push_back(current->children[i]);
	      }
	 }
	 return res;
    }
    // time: O(n) where n is the number of nodes
    // space: O(n) if there is a big chain
    // time elapsed to solve it: 7 min.
    // improvements: it could be done passing an array as reference which won't require a lot of memory..
    vector<int> solve(Node *current){
	 if(!current)return {};
	 vector<int> res;
	 res.push_back(current->val);
	 for(auto _child:current->children){
	    for(auto item:solve(_child)) res.push_back(item);
	 }
	 return res;
    }
    vector<int> preorder(Node* root) {
	 return solve_iterativelly(root);
    }
};
