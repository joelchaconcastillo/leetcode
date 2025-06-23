class MovingAverage {
public:
    double sum = 0.0;
    deque<int> dq;
    int size;
    MovingAverage(int size) {
       this->size = size; 
       sum = 0;
    }
    
    double next(int val) {
	    dq.push_back(val);
	    sum+=val;
	    if(dq.size() > this->size){
		    sum -= dq.front();
		    dq.pop_front();
	    }
	    return sum/dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
