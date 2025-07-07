/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
	    vector<ImmutableListNode *> all;
	    auto current = head;
	    while(current){
		    all.push_back(current);
		    current = current->getNext();
	    }
	    reverse(all.begin(), all.end());
	    for(auto c:all)c->printValue();
    }
};
