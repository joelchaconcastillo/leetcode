class MaxStack {
public:
    multiset<pair<int, int>> _sorted_stack, _indexed_stack;
    //ST --> val, idx, 
    //ID --> idx, val
    int index = 0;
    MaxStack() {
        
    }
    
    void push(int x) {
	 _sorted_stack.insert({x, index});
	 _indexed_stack.insert({index, x});
	 index++;
    }
    
    int pop() {
        auto [idx, val] = *(_indexed_stack.rbegin());
	_indexed_stack.erase(_indexed_stack.find({idx, val}));
	_sorted_stack.erase(_sorted_stack.find({val, idx}));
	return val;
    }
    
    int top() {
	return (_indexed_stack.rbegin())->second;
    }
    
    int peekMax() {
        return (_sorted_stack.rbegin())->first;
    }
    
    int popMax() {
        auto [val, idx] = *(_sorted_stack.rbegin());
	_indexed_stack.erase(_indexed_stack.find({idx, val}));
	_sorted_stack.erase(_sorted_stack.find({val, idx}));
	return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
