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
    vector<vector<int>> solve(TreeNode *root){
	  if(!root)return {};
	  vector<vector<int> > res;
	  queue<TreeNode*> q;
	  q.push(root);
	  while(!q.empty()){
	       queue<TreeNode*> tmp;
	       vector<int> row;
	       while(!q.empty()){
		    auto _current = q.front(); q.pop();
		    row.push_back(_current->val);
		    if(_current->left)tmp.push(_current->left);
		    if(_current->right) tmp.push(_current->right);
	       }
	       if(!row.empty())res.push_back(row);
	       q = tmp;
	  }
	  reverse(res.begin(), res.end());
	  return res;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	return solve(root);
    }
};
