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
class FindElements {
public:
    unordered_set<int> marked;
    FindElements(TreeNode* root) {
	transverse(root);
    }
    bool transverse(TreeNode *root, int current = 0){
	 if(!root) return false;
	 marked.insert(current);
	 return transverse(root->left, current*2+1) ||
		 transverse(root->right, current*2+2);
    }
    bool find(int target) {
	  return marked.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
