class Solution {
public:
    int solve(vector<string> &words){
	    int n = words.size();
	    int res = 0;
	    vector<unordered_set<char> > uniq_words;
	    for(auto word:words){
		    unordered_set<char>universe;
		    for(auto letter:word) universe.insert(letter);
		    uniq_words.push_back(universe);
	    }
	    for(int i = 0; i < n; i++){
		    for(int j = i+1; j < n; j++){
			    bool has_common=false;
			    for(auto letter:uniq_words[i]){
				    if(uniq_words[j].count(letter)){
					    has_common = true;
					    break;
				    }
			    }
			    if(has_common)continue;
			    res = max(res, static_cast<int> ( words[i].size()*words[j].size() ));
		    }
	    }
	    return res;
    }
    int solve2(vector<string> &words){
	    int n = words.size();
	    unordered_map<int, int> maskLen;
	    for(auto &word:words){
		    int mask = 0;
		    for(auto &letter:word){
			    int bitletter = letter-'a';
			    mask |= (1<<bitletter);
		    }
		    maskLen[mask] = max(maskLen[mask], static_cast<int> (word.size()));
	    }
	    int res = 0;
	    for(auto [mask1, len1]:maskLen){
		    for(auto [mask2, len2]: maskLen){
			    if((mask1&mask2) !=0) continue;
			    res = max(res, (len1*len2));
		    }
	    }
	    return res;
    }
    int maxProduct(vector<string>& words) {
	    return solve2(words);
	    return solve(words);
    }
};

/*
 
    word1 = abc   word2 = cde
    a uf
    b uf
    c uf

 *
 * */
