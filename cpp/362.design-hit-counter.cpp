class HitCounter {
    queue<pair<int, int>> hits;
    int current_sz = 0;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
	    if(hits.empty()){
		    hits.push({timestamp, 1});
		    current_sz++;
		    return;
	    }
	    if(hits.back().first == timestamp){
		    hits.back().second++;
		    current_sz++;
		    return;
	    }
	    hits.push({timestamp, 1});
	    current_sz++;
    }
    
    int getHits(int timestamp) {
	while(!hits.empty() && timestamp-hits.front().first>=300 ){
		current_sz -= hits.front().second;
		hits.pop();
	}
	return current_sz;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
// 1 2 3   300 
//       4     300 301
//       3     4   3  
