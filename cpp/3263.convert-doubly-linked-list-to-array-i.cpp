/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> solve(Node *head){
		vector<int> res;
		auto current = head;
		while(current){
			res.push_back(current->val);
			current = current->next;
		}
		return res;
	}
	vector<int> toArray(Node *head){
		return solve(head);
	}
};
