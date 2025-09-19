class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        unordered_map<string, int> prefixes;
	sentence +=" ";
        string current = "";
	int ans = -1, cont=1;
        for(auto letter:sentence){
		if(current == searchWord)return cont;
		if(letter ==' '){
			if(current.empty())continue;
			current = "";
			cont++;
		}else current +=letter;
	}	
	return ans;
    }
};
