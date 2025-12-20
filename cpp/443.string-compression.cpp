class Solution {
public:
    int solve(vector<char> &chars){
	int i = 0, j = 0, n = chars.size(), cont=0;
	char prev = chars[0];
	while(j < n){
		if(chars[j] != prev){
			auto str_cont = to_string(cont);
			chars[i++] = prev;
			for(int k = 0 ; cont>1 && k < str_cont.size(); k++){
				chars[i++] = str_cont[k];
			}
			cont = 0;
		}
		cont++;
		prev = chars[j++];
	}
	if(cont){
	   auto str_cont = to_string(cont);
	   chars[i++] = prev;
	    for(int k = 0 ; cont >1 && k < str_cont.size(); k++)chars[i++] = str_cont[k];
	}
	return i;
    }
    int compress(vector<char>& chars) {
	    return solve(chars);
    }
};
