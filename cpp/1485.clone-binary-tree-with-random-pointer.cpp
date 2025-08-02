/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 *
 *
 *  1) create copy and index source
 *  2) go on each item in the indexed list (hash) and replicate random pointers
 */

class Solution {
public:
    NodeCopy* dfs(Node *current, unordered_map< Node*, NodeCopy*> &origin_copy){
	    if(!current)return NULL;
	    NodeCopy * copy_current = new NodeCopy(current->val);
	    origin_copy[current] = copy_current;
	    copy_current->left = dfs(current->left, origin_copy);
	    copy_current->right= dfs(current->right, origin_copy);
	    return copy_current;

    } 
    NodeCopy* solve(Node *root){
	    unordered_map<Node*, NodeCopy*> origin_copy;
	    NodeCopy* copy = dfs(root, origin_copy);
	    for(auto [source, copy]:origin_copy){
		    if(source->random) copy->random = origin_copy[source->random];
	    }
	    return copy;
    }
    NodeCopy* dfs2(Node *current, unordered_map<Node*, NodeCopy*> &visited){
	    if(!current) return NULL;
	    if(visited.count(current))return visited[current];
	    visited[current] = new NodeCopy(current->val);
	    visited[current]->left = dfs2(current->left, visited);
	    visited[current]->right = dfs2(current->right, visited);
	    visited[current]->random = dfs2(current->random, visited);
	    return visited[current];
    }
    NodeCopy* solve2(Node *root){
	    unordered_map<Node*, NodeCopy*> visited;
	    return dfs2(root, visited);
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
	    return solve2(root);
	    return solve(root);
    }
};
