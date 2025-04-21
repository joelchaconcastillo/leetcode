class SmallestInfiniteSet {
    set<int>_reinserted;
    int current_smallest;
public:
    SmallestInfiniteSet() {
       current_smallest = 1; 
    }
    
    int popSmallest() {
	if(!_reinserted.empty()){
	   int element = *_reinserted.begin();
	   _reinserted.erase(element);
	   return element;
	}else{
	   current_smallest++;
	   return current_smallest-1;
	}
    }
    
    void addBack(int num) {
	 if(num < current_smallest) _reinserted.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
