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
//edge cases, 
//		prefix sum is equal to targetSum
//              max prefix sum  > 1x10^9
class Solution {
public:
    unordered_map<long long, long long> freq;
    long long helper(TreeNode* current, long long targetSum, long long prefixSum){
	    if(!current)return 0;
	    prefixSum += current->val;
	    long long rem = prefixSum-targetSum;
	    long long res = freq[rem]+(targetSum==prefixSum);
	    freq[prefixSum]++;
	    if(!current->left && !current->right){
		    freq[prefixSum]--;
		    return res;
	    }
	    long long _left = helper(current->left, targetSum, prefixSum);
	    long long _right = helper(current->right, targetSum, prefixSum);
	    freq[prefixSum]--;
	    return res+_left+_right;
    }
    int pathSum(TreeNode* root, int targetSum) {
	    return helper(root, targetSum, 0);
    }
};
