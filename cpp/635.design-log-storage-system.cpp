class LogSystem {
public:
    multiset<pair<string, int>> memo;
    LogSystem() {
        
    }
    string parse_date(string &timestamp, string gran, char replace){
	    string res = timestamp;
	    //Year
	    if(gran == "Year") res[4]=replace;
	    //Month
	    if(gran == "Month") res[7]=replace;
	    //Day
	    if(gran == "Day") res[10]=replace;
	    //hour
	    if(gran == "Hour") res[13]=replace;
	    //Minute
	    if(gran == "Minute") res[16]=replace;
	    return res;
    }    
    void put(int id, string timestamp) {
	    memo.insert({timestamp,id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
	    vector<int> res;
	    auto l_start = parse_date(start, granularity, ':'-1);
	    auto l_end = parse_date(end, granularity, ':'+1);
	    auto start_it = memo.lower_bound({l_start,-1});
	    auto end_it = memo.upper_bound({l_end, INT_MAX});
	    while(start_it != end_it){
		    res.push_back(start_it->second);
		    start_it++;
	    }
	    return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
