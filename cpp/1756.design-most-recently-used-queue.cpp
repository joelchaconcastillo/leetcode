class MRUQueue {
public:
    vector<deque<int> > buckets;
    int n, size_bucket;
    MRUQueue(int n):n(n) {
	    this->size_bucket = max(3, (int)ceil(sqrt(n))); //2
	    int n_buckets = ceil(n/static_cast<double>(size_bucket));
	    buckets.assign(n_buckets, deque<int>());
	    for(int i = 1; i <=n ;i++){
		    int current_bucket = (i-1)/this->size_bucket;
		    buckets[current_bucket].push_back(i);
	    }
    }
    int fetch(int k) {
	    int current_bucket = (k-1)/size_bucket;//2/2 --> 1
	    int pos_in_bucket = (k-1)%size_bucket;//0
	    int val = buckets[current_bucket][pos_in_bucket];
	    //re-balance buckets..
	    while(pos_in_bucket+1 < buckets[current_bucket].size()){
		    buckets[current_bucket][pos_in_bucket] = 
		    buckets[current_bucket][pos_in_bucket+1];
		    pos_in_bucket++;
	    }
	    buckets[current_bucket].pop_back();
	    buckets.back().push_back(val);
	    while(current_bucket+1 < buckets.size()){
		    buckets[current_bucket].push_back(buckets[current_bucket+1].front());
		    buckets[current_bucket+1].pop_front();
		    current_bucket++;
	    }
	    return val;
    }
};

