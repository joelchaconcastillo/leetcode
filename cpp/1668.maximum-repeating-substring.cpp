class Solution {
public:

    int maxRepeating(string sequence, string word) {
	    unordered_set<string> exists;
	    int n = sequence.size();
	    for(int i = 0 ;i  <n ;i++){
		    string current = "";
		    for(int j = i; j < n; j++){
			    current+=sequence[j];
			    exists.insert(current);
		    }
	    }
	    if(!exists.count(word))return 0;
	    int res = 1;
	    string current = word;
	    while(exists.count(current+word)) current += word;
	    return current.size()/word.size();
    }
    //faster alternatives..
    //try a KMP for each word on sequence
    //rolling hashing + rabin karp
};
