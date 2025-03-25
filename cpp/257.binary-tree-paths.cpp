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
    vector<string> res;
    void transverse(TreeNode *current, string path=""){
	if(!current) return;
	if(!current->left && !current->right){
	  path+=to_string(current->val);
	  res.push_back(path);
	  return;
	}
	path+=to_string(current->val)+"->";
	transverse(current->left, path);
	transverse(current->right, path);
    }
    //time: O(n)
    //space: O(max h)
    //elapsed time to resolve: 5 min.
    vector<string> solve(TreeNode *node){
	    transverse(node);
	    return res;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
	   return solve(root);
    }
};
