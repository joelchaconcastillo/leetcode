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
    void explore_levels(TreeNode *current, unordered_map<TreeNode*, int> &levels, unordered_map<TreeNode*, TreeNode*> &parents, TreeNode* prev=NULL, int level=0){
	    if(!current) return;
	    parents[current]=prev;
	    levels[current]=level;
	    explore_levels(current->left, levels, parents, current, level+1);
	    explore_levels(current->right, levels, parents, current, level+1);
    } 
    TreeNode *solve(TreeNode *root){
	    unordered_map<TreeNode*, int> levels;
	    unordered_map<TreeNode*, TreeNode*>parents;
	    explore_levels(root, levels, parents);
	    TreeNode *wrongNode = root;
	    for(auto [node, level]:levels){
		    if(node->left && levels[node->left] == level){
			    wrongNode = node;
			    break;
		    }else if(node->right && levels[node->right] == level){
			    wrongNode = node;
			    break;
		    }
	    }
	    if(parents[wrongNode]->left == wrongNode){
		    parents[wrongNode]->left = NULL;
	    }
	    if(parents[wrongNode]->right == wrongNode){
		    parents[wrongNode]->right = NULL;
	    }
	    return root;
    }
    TreeNode* correctBinaryTree(TreeNode* root) {
	    return solve(root);
    }
};
