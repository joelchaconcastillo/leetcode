class Solution {
public:
    string capitalizeTitle(string title) {
	    string res, current="";
	    auto normalize = [](const string &st){
		    auto current = st;
		    for(auto &i:current)i=tolower(i);
		    if(current.size()>2) current[0] = toupper(current[0]);
		    return current;
	    };
	    for(int i = 0 ; i < title.size(); i++){
		    if(title[i]==' '){
			    res += normalize(current)+" ";
			    current="";
		    }else
		    current+=title[i];
	    }
	    if(!current.empty()){
		    res += normalize(current);
	    }
	    return res;
    }
};
