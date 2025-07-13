class Solution {
public:
    bool is_nice(unordered_map<char, int> &freq){
	    for(auto [letter, count]:freq){
		    if( !freq.count(toupper(letter)) || !freq.count(tolower(letter))) return false;
	    }
	    return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.size();
	string longest ="";
        for(int l = 1; l <=n; l++){
		unordered_map<char, int> freq;
		for(int i = 0; i<n; i++){
			freq[s[i]]++;
			int delta =i-l;/// Bb
			if(delta>=0){
			    freq[s[delta]]--;
			    if(freq[s[delta]]==0)freq.erase(s[delta]);
			}
			if(i-l+1>=0)
			if(is_nice(freq) && longest.size() < l)longest = s.substr(i-l+1, l);
		}
	}
	return longest;
    }
};
