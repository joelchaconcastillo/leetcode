class Solution {
public:
   /*
     time: O(n)
     space: O(n)
     elapsed time to solve: 13
    * */
    string solve(string &st){
       string res="";
       stringstream ss(st);
       string word="";
       int index = 1;
       while(ss>>word){
	    if(word.empty())break;
	    string new_word="";
	    if(tolower(word[0]) == 'a' || tolower(word[0]) == 'e' || tolower(word[0]) == 'i' || tolower(word[0]) =='o' || tolower(word[0]) == 'u'){
		    new_word = word+"ma";
	    }
	    else{
		    new_word = word.substr(1, word.size()-1)+word.substr(0,1)+"ma";
	    }
	    res += new_word + string(index,'a')+" "; 
	    index++;
       }
       res.pop_back();
       return res;
    }
    string toGoatLatin(string sentence) {
	return solve(sentence);
    }
};
