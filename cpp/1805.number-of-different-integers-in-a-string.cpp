class Solution {
public:
    int numDifferentIntegers(string word) {
	    unordered_set<string> numbers;
	    string tmp = "";
	    word += "l";
	    for(auto &letter:word){
		    if(isdigit(letter)){
			    tmp+=letter;
		    }else{
			    if(!tmp.empty()){
				    while(tmp.size() > 1 && tmp[0] =='0'){
					    tmp.erase(tmp.begin(), tmp.begin()+1);
				    }
				    numbers.insert(tmp);
			    }
			    tmp="";
		    }
	    }
	    return numbers.size();
    }
};
