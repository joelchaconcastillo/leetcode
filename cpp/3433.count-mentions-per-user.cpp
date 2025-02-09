class Solution {
public:
    bool isOnline(int id, vector<int> &timesOffline, int timestamp){
	    for(auto time:timesOffline){ // it can be improved by sorting events!!
		    if(time<=timestamp && time+60>timestamp)return false;
	    }
	    return true;
    }
    // time: O(E*U*T)
    // space: O(U*T)
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
       vector<int> mentions(numberOfUsers, 0);
       vector<vector<int>> users_mentions_offline(numberOfUsers);
       int allcount = 0;
       for(auto event:events){
          if(event[0] == "OFFLINE"){
		     int timestamp = stoi(event[1]);
		     int id = stoi(event[2]);
		     users_mentions_offline[id].push_back(timestamp);
	  }else if(event[2]=="ALL")  allcount++;
       }

       for(auto event:events){//1e5
	       int timestamp = stoi(event[1]);
	       if(event[2] == "HERE"){
		  for(int i = 0 ; i < numberOfUsers; i++){ //100
		      mentions[i] += isOnline(i, users_mentions_offline[i], timestamp);
		  }
	       }else if(event[0] == "MESSAGE" && event[2] != "HERE" && event[2] != "ALL"){
		       stringstream ss(event[2]);
		       string sid;
		       while(ss>>sid){
			       int id = stoi(sid.substr(2,sid.size()-2));
			       mentions[id]++;
		       }
	       }

       }
       for(auto &i:mentions) i+=allcount;
       return mentions;       
    }
};
