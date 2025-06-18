class Solution {
public:
    int solve(string &st){
	    unordered_map<char, int> vowel, consonants;
	    int maxv=0, maxc=0;
	    for(auto letter:st){
		    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') vowel[letter]++;
		    else consonants[letter]++;
		    maxc = max(maxc, consonants[letter]);
		    maxv = max(maxv, vowel[letter]);
	    }
	    return maxv+maxc;
    }
    int maxFreqSum(string s) {
	    return solve(s);
    }
};
