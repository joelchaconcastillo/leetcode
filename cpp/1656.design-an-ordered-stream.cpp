class OrderedStream {
public:
    vector<string> values;
    vector<bool> marked;
    int ptr = 0;
    OrderedStream(int n) {
	    values.assign(n, "");
	    marked.assign(n, false);
    }
    
    vector<string> insert(int idKey, string value) {
	    vector<string> res;
	    values[idKey-1]=value;
	    marked[idKey-1]=true;

	    while( ptr < values.size() && marked[ptr]){
		    res.push_back(values[ptr]);
		    marked[ptr]=false;
		    ptr++;
	    }
	    return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
