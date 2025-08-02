/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *solve(Node *head){
	    unordered_map<Node*, Node*> visited;
	    auto current = head;
	    while(current){
		    visited[current] = new Node(current->val);
		    current = current->next;
	    }
	    current = head;
	    while(current){
		    visited[current]->next = visited[current->next];
		    visited[current]->random = visited[current->random];
		    current = current->next;
	    }
	    return visited[head];
    }
    Node *dfs(Node *current, unordered_map<Node*, Node*> &visited){
	    if(!current) return NULL;
	    if(visited.count(current))return visited[current];
	    visited[current] = new Node(current->val);
	    visited[current]->next = dfs(current->next, visited);
	    visited[current]->random = dfs(current->random, visited);
	    return visited[current];
    }
    Node *solve2(Node *head){
	    unordered_map<Node*, Node*> visited;
	    return dfs(head, visited);
    }
    Node* copyRandomList(Node* head) {
	return solve2(head);
        return solve(head);	    
    }
};
