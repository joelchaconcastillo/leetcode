class Solution {
public:
    bool isCircularSentence(string sentence) {
	    sentence +=' ';
	    sentence+= sentence[0];
	    sentence+= ' ' ;
	    int n = sentence.size();
	    string current = "", lastWord="";;
	    for(int i = 0 ; i < n; i++){
		    if(sentence[i] == ' '){
			    if(!lastWord.empty() && lastWord.back()!=current.front())return false;
			    lastWord = current;
			    current = "";
		    }else current += sentence[i];
	    }
	    return true;
    }
};
