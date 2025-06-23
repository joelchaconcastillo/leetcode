/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string solve(RopeTreeNode *current){
	    if(!current)return "";
	    string res = solve(current->left)+solve(current->right);
	    if(!current->val.empty())res += current->val;
	    return res;
    }
    char getKthCharacter(RopeTreeNode* root, int k) {
	    string res = solve(root);
	    return res[k-1];
    }
};
