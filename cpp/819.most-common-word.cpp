class Solution {
public:
    string solve(string &p, vector<string> &b){
	    unordered_set<string> banned;
	    for(auto word:b){
		    for(auto &letter:word)letter = tolower(letter);
		    banned.insert(word);
	    }
	    unordered_map<string, int> freq;
	    int res = 0;
	    string ans = "";
	    istringstream ist(p);
	    string old_word;
	    while(ist>>old_word){
		    istringstream ist2(old_word);
		    string word2;
		    while(getline(ist2, word2, ',')){
			    string word="";
			    for(auto letter:word2){
				    if(!isalpha(letter))continue;
				    word+=tolower(letter);
			    }
			    if(banned.count(word))continue;
			    freq[word]++;
			    if(freq[word] > res){
				    res = freq[word];
				    ans = word;
			    }
		    }
		    
	    }
	    return ans;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
	    return solve(paragraph, banned);
    }
};
