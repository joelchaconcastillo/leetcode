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
    vector<vector<int> > solve(TreeNode *root){
	    if(!root)return {};
	  vector<vector<int> > res;
	  queue<TreeNode*> q;
	  q.push(root);
	  int level = 0;
	  while(!q.empty()){
		int sz = q.size();
		vector<int> tmp;
		while(sz--){
			auto current = q.front(); q.pop();
			tmp.push_back(current->val);
			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
		}
		if(level%2==1){
			reverse(tmp.begin(), tmp.end());
		}
		res.push_back(tmp);
		level++;
	  }
	  return res;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	 return solve(root);
    }
};
