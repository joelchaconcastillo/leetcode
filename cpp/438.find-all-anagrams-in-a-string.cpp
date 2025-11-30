class Solution {
public:
    vector<int> solve(string s, string p) {
	    int m = p.size();
	    unordered_map<char, int> ref_freq, freq;
	    for(auto letter:p)ref_freq[letter]++;
	    vector<int> res;
	    int match = 0, unmatch = 0;
	    for(int i = 0; i < s.size(); i++){
		    freq[s[i]]++;

		    if(freq[s[i]] <= ref_freq[s[i]]) match++;
		    else unmatch++;

		    if(i-m+1>=0 && match == m && unmatch == 0){
			    res.push_back(i-m+1);
		    }
		    if(i-m+1>=0){
			  freq[s[i-m+1]]--;
			  if(freq[s[i-m+1]] >= ref_freq[s[i-m+1]]) unmatch--;
			  else match--;
		    }
	    }
	    return res;
    }
    vector<int> solve2(string s, string p) {
	    int m = p.size(), unmatch=0, match=0;
	    vector<int>res;
	    unordered_map<char, int> ref_freq, freq;
	    for(auto letter:p)ref_freq[letter]++;
	    for(int i = 0 ;i+1 < m; i++){
		    freq[s[i]]++;
		    if(freq[s[i]] <= ref_freq[s[i]])match++;
		    else unmatch++;
	    }
	    for(int i = m-1; i < s.size(); i++){
		    freq[s[i]]++;
		    if(freq[s[i]] <= ref_freq[s[i]]) match++;
		    else unmatch++;
		    if(match == m && unmatch==0){
			    res.push_back(i-m+1);
		    }
		    freq[s[i-m+1]]--;
		    if(freq[s[i-m+1]] >= ref_freq[s[i-m+1]]) unmatch--;
		    else match--;
	    }
	    return res;
    }
    vector<int> findAnagrams(string s, string p) {
	    return solve2(s, p);
	    return solve(s, p);
    }
};
