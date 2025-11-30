class Solution {
public:
    int solve(int num) {
	string num_str = to_string(num);
	int minv = num, maxv=num;
	for(char i = '0'; i <='9'; i++){
	    for(char j = '0'; j <='9'; j++){
		    auto tmp = num_str;
		    for(auto &ii:tmp){
			    if(ii==i)ii=j;
		    }
		    if(tmp[0]=='0')continue;
		    maxv = max(maxv, stoi(tmp));
		    minv = min(minv, stoi(tmp));
	    }
	}
	return maxv-minv;
    }
    int solve2(int num) {
	string tmp = to_string(num);
	int n = tmp.size();
	int maxv = num;
	int i = 0;
	while(i<tmp.size() && tmp[i]=='9')i++;
	if(i<tmp.size()){
	  char digm = tmp[i];
	  for(auto &ii:tmp) if(ii==digm) ii='9';
	  maxv = stoi(tmp);
	}
	tmp = to_string(num);
	int minv=num;
	i = 0;
	while(i < tmp.size() && tmp[i]=='1')i++;
	if( i < tmp.size()){
	    char dig = tmp[i];
	    if(tmp[0] != '1'){
		    for(auto &ii:tmp) if(ii==dig)ii='1';
	    }else{
		    while(i<tmp.size() && (tmp[i]=='0' || tmp[i]=='1') )i++;
		    if(i<n){
		      dig = tmp[i];
		      for(auto &ii:tmp) if(ii==dig)ii='0';
		    }
	    }
	    minv = stoi(tmp);
	}
	return maxv-minv;
    }
    int maxDiff(int num) {
	return solve2(num);
	return solve(num);
    }
};
