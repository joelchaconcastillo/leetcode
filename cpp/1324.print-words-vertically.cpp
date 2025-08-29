class Solution {
public:
    vector<string> printVertically(string s) {
	    s +=" ";
	    vector<string> words;
	    string current="";
	    int maxS = 0;
	    for(auto i:s){
		    if(i==' '){
			    words.push_back(current);
			    maxS = max(maxS, (int)current.size());
			    current="";
		    }else current +=i;
	    }
	    vector<string> res(maxS);
	    for(int i = 0 ; i < maxS; i++){
		    for(int j = 0 ; j < words.size(); j++){
			    if( i < words[j].size())res[i] += words[j][i];
			    else res[i]+=" ";
		    }
	    }
	    for(auto &word:res) while(!word.empty() && word.back()==' ')word.pop_back();
	    return res;
    }
};
