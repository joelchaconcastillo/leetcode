class WordDistance {
public:
    unordered_map<string, vector<int>>word2Index;
    WordDistance(vector<string>& wordsDict) {
	    int n = wordsDict.size();
	    for(int i = 0 ; i < n ;i++){
		    word2Index[wordsDict[i]].push_back(i);
	    }
    }
    
    int shortest(string word1, string word2) {
	    int res = INT_MAX;
	    for(auto &idxi:word2Index[word1]){
	       for(auto &idxj:word2Index[word2]){
		       res = min(abs(idxi-idxj), res);
	       }
	    }
	    return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
