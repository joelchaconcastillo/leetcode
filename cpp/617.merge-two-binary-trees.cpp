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
    TreeNode * helper(TreeNode *current1, TreeNode *current2){
	  if(!current1 && !current2)return NULL;
	  int sum = 0;
	  if(current1)sum+=current1->val;
	  if(current2) sum+=current2->val;
	  TreeNode * left1 = (current1 && current1->left)?current1->left: NULL;
	  TreeNode * left2 = (current2 && current2->left)?current2->left: NULL;

	  TreeNode * right1 = (current1 && current1->right)?current1->right: NULL;
	  TreeNode * right2 = (current2 && current2->right)?current2->right: NULL;
	  TreeNode * current3 = new TreeNode(sum);
	  current3->left = helper(left1, left2);
	  current3->right = helper(right1, right2);
	  return current3;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	    return helper(root1, root2);
    }
};
