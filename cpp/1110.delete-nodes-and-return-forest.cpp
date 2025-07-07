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
    void dfs(TreeNode *current, unordered_set<int> &to_delete, vector<TreeNode *> &roots, TreeNode* parent=NULL){
	    if(!current) return;
	    if(current->left){
		    dfs(current->left, to_delete, roots, current);
	    }
	    if(current->right){
		    dfs(current->right, to_delete, roots, current);
	    }
	    if( to_delete.count(current->val)){
		    if(current->left)
		    roots.push_back(current->left);
		    if(current->right)
		    roots.push_back(current->right);
		    current->left = NULL;
		    current->right = NULL;
		    if(parent && parent->left == current) parent->left = NULL;
		    if(parent && parent->right == current) parent->right = NULL;
	    }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
	    unordered_set<int> to_delete_set;
	    vector<TreeNode *> roots;
	    for(auto val:to_delete) to_delete_set.insert(val);
	    dfs(root, to_delete_set, roots);
	    if(!to_delete_set.count(root->val)) roots.push_back(root);
	    return roots;
    }
};
