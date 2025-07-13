class Solution {
public:
    char solve(int k){
	    string word="a";
	    while(word.size() < k){
		    auto tmp = word;
		    for(auto letter:tmp){
			    letter++;
			    if(letter>'z') letter='a';
			    word+=letter;
		    }
	    }
	    return word[k-1];
    }
    char kthCharacter(int k) {
	    return solve(k);
    }
};
