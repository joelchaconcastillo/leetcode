class Node{
    public:
    unordered_set<string> items;
    int index;
          Node *prev, *next;
	    Node(){}
	    Node(int index){
		 this->index = index;
	    }
};
class AllOne {
    Node *head, *tail;
    unordered_map<string, int> freq;
    unordered_map<int, Node*> indexedNode;

public:
    AllOne() {
       head = new Node(0); //dummy variables
       tail = new Node(10000000); //dummy variables
       head->next = tail;
       head->prev = NULL;
       tail->next = NULL;
       tail->prev = head;
       indexedNode[0] = head;
    }
    void insert(string &key, int idx, Node *&current, Node *prev, Node *next){
	 if(!current){ // it doesn't exist
	     current = new Node(idx);
	     current->items.insert(key);
	     current->prev = prev;
	     current->next = next;
	     next->prev = current;
	     prev->next = current;
	 }
	 current->items.insert(key);
    }

    void remove(string &key, int count, Node *&current){
	 if(!current) return;
	 if(current->items.size() == 1){ //remove node
	     current->prev->next = current->next;
	     current->next->prev = current->prev;
	     delete current;
	     current = NULL;
	     return;
	 }
	 current->items.erase(key);
    }

    void inc(string key) {
	 auto count = freq[key];
	 insert(key, count+1, indexedNode[count+1], indexedNode[count], indexedNode[count]->next);
	 if(count>0) remove(key, count, indexedNode[count]);
	 freq[key]++;
	 auto tmp = head;
    }

    void dec(string key) {
	 auto count = freq[key];
	 if(count==0)return ;
	 if(count>1) insert(key, count-1, indexedNode[count-1], indexedNode[count]->prev, indexedNode[count]);
	 remove(key, count, indexedNode[count]);
	 freq[key]--;
    }
    
    string getMaxKey() {
       if(tail->prev == head)return "";
       return *(tail->prev->items.begin());
    }
    
    string getMinKey() {
        if(head->next == tail)return "";
       return *(head->next->items.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
