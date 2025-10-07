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
    vector<vector<int>> levelOrder(Node* root) {
	 if(!root)return {};
         queue<Node*> q;
	 q.push(root);
	 vector<vector<int> > res;
	 while(!q.empty()){
		 int _sz = q.size();
		 vector<int>  level;
		 for(int i = 0; i < _sz; i++){
			 auto current = q.front();q.pop();
			 for(auto _to:current->children){
				 if(_to)q.push(_to);
			 }
			 level.push_back(current->val);
		 }
		 res.push_back(level);
	 }
	 return res;
    }
};
