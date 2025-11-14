/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()){
	   auto current = q.front(); q.pop();
	   int cont = 0;
	   if(current->left){
		   q.push(current->left);
		   cont++;
	   }
	   if(current->right){
		   q.push(current->right);
		   cont++;
	   }
	   if(cont == 1){
		   if(current->left) res.push_back(current->left->val);
		   if(current->right) res.push_back(current->right->val);
	   }
	}
	return res;
    }
};
