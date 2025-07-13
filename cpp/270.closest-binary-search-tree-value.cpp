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
    //dist, value
    pair<double, int> search(TreeNode *current, double target){
	    pair<double, int> res(INT_MAX, INT_MAX);
	    if(!current) return res;
	    res = min(res, {fabs(current->val-target), current->val});
	    if(target <= current->val){
		    res = min(res, search(current->left, target));
	    }else{
		    res = min(res, search(current->right, target));
	    }
	    return res;
    }
    int closestValue(TreeNode* root, double target) {
	    return search(root, target).second;
    }
};
