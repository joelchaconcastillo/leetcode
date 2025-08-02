/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *dfs(Node *current, unordered_map<Node*, Node*> &visited){
	    if(!current) return NULL;
	    if(visited.count(current))return visited[current];
	    visited[current] = new Node(current->val);
	    for(auto to:current->neighbors){
		    visited[current]->neighbors.push_back(dfs(to, visited));
	    }
	    return visited[current];
    }
    Node* solve(Node *node){
	    unordered_map<Node *, Node *> visited;
	    return dfs(node, visited);
    }
    Node* cloneGraph(Node* node) {
	    return solve(node);
    }
};
