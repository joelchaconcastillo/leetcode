class Solution {
public:
    int countVowelSubstrings(string word) {
	    int n = word.size();
	    int res = 0;
	    for(int i = 0; i < n; i++){
		    set<char> existent;
		    for(int j = i; j < n; j++){
			    if( word[j] == 'a' || word[j]=='e' ||word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
				    existent.insert(word[j]);
			    else break;
			    if(existent.size() == 5) res++;
		    }
	    }
	    return res;
    }
};
