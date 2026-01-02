class Solution {
public:
    int countTime(string time) {
        int res =0 ;
	for(int i =0  ;i  < 24; i++){
		for(int j = 0 ; j < 60; j++){
			string h = to_string(i), m = to_string(j);
			if(i<10)h = "0"+h;
			if(j<10)m = "0"+m;
			bool same = true;
			string time2 = h+":"+m;
			for(int k = 0; k < time.size(); k++){
				if(time[k] == '?')continue;
				if(time2[k] != time[k]) same=false;
			}
			res += same;
		}
	}
	return res;	
    }
};
