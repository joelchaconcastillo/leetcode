class Solution {
public:
    unordered_map<string, int> split(string s){
          unordered_map<string, int> freq;
	  string word="";
	  s+=" ";
          for(auto letter:s){
		  if(letter==' '){
			  freq[word]++;
			  word="";
		  }else word+=letter;
	  }	  
	  return freq;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
	    auto freq = split(s1+" "+s2);
	    vector<string> res;
	    for(auto [word, cont]:freq){
		    if(cont==1)res.push_back(word);
	    }
	    return res;
    }
};
