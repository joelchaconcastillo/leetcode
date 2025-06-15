class LFUCache2 {
    struct Node {
        int freq;
        list<int> keys;
        Node* prev;
        Node* next;
        Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, int> key_value;                    // key -> value
    unordered_map<int, Node*> key_node;                   // key -> frequency node
    unordered_map<int, list<int>::iterator> key_iter;     // key -> iterator in node->keys

    Node* head;  // Dummy head
    Node* tail;  // Dummy tail

public:
    LFUCache2(int capacity) : capacity(capacity) {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    ~LFUCache2() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        if (key_value.find(key) == key_value.end())
            return -1;
        updateFreq(key);
        return key_value[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_value.find(key) != key_value.end()) {
            key_value[key] = value;
            updateFreq(key);
            return;
        }

        if (key_value.size() >= capacity) {
            evict();
        }

        key_value[key] = value;
        insertKey(key);
    }

private:
    void insertKey(int key) {
        Node* node;
        if (head->next == tail || head->next->freq != 1) {
            node = new Node(1);
            insertAfter(head, node);
        } else {
            node = head->next;
        }

        node->keys.push_front(key);
        key_node[key] = node;
        key_iter[key] = node->keys.begin();
    }

    void updateFreq(int key) {
        Node* node = key_node[key];
        auto it = key_iter[key];
        int freq = node->freq;

        // Remove key from current node
        node->keys.erase(it);

        Node* nextNode;
        if (node->next == tail || node->next->freq != freq + 1) {
            nextNode = new Node(freq + 1);
            insertAfter(node, nextNode);
        } else {
            nextNode = node->next;
        }

        // Add key to next freq node
        nextNode->keys.push_front(key);
        key_node[key] = nextNode;
        key_iter[key] = nextNode->keys.begin();

        // Delete node if empty
        if (node->keys.empty()) {
            remove(node);
        }
    }

    void evict() {
        if (head->next == tail) return;  // No real node

        Node* node = head->next;
        int key = node->keys.back();
        node->keys.pop_back();

        if (node->keys.empty()) {
            remove(node);
        }

        key_value.erase(key);
        key_node.erase(key);
        key_iter.erase(key);
    }

    void insertAfter(Node* prev, Node* node) {
        node->prev = prev;
        node->next = prev->next;
        prev->next->prev = node;
        prev->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};
class LFUCache{
	unordered_map<int, list<pair<int, int>>> freq;
	unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
	int capacity, minf;

   public:
	LFUCache(int capacity): capacity(capacity), minf(0){}
	int get(int key){
		if(!cache.count(key))return -1;
		//get current data
		const int current_freq = cache[key].first;
		auto ite_list = cache[key].second;
		auto key_val_pair = *ite_list;
		//remove key data
		freq[current_freq].erase(ite_list);
		if(freq[current_freq].empty()){
			freq.erase(current_freq);
			if(minf==current_freq)minf++;
		}
		//insert it
		freq[current_freq+1].push_back(key_val_pair);
		cache[key] = {current_freq+1, --freq[current_freq+1].end()};
		return key_val_pair.second;
	}
	void put(int key, int value){
		if(capacity<=0)return;
		if(cache.count(key)){ //just move it
		    cache[key].second->second=value; 
		    get(key);
		    return;
		}
		if(capacity == cache.size()){
		   cache.erase(freq[minf].front().first);
		   freq[minf].pop_front();
		   if(freq[minf].empty()) freq.erase(minf);
		}
		minf = 1;
		freq[minf].push_back({key, value});
		cache[key] = {minf, --freq[minf].end()};
	}
};
