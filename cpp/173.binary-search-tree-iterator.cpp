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
class BSTIterator {
public:
    vector<TreeNode*> stack;
    void fill_lefts(TreeNode *current){
	    while(current){
		    stack.push_back(current);
		    current = current->left;
	    }
    }
    BSTIterator(TreeNode* root) {
	    this->fill_lefts(root);
    }
    
    int next() {
	    auto visited = stack.back();
	    stack.pop_back();
	    if(visited->right) fill_lefts(visited->right);
	    return visited->val;
    }
    
    bool hasNext() {
	    return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
