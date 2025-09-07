class Solution {
public:
    bool isPossible(unordered_map<char, int> freqPlate, string &word){
	    for(auto letter:word){
		    freqPlate[letter]--;
	    }
	    for(auto [letter, cont]:freqPlate) if(cont > 0)return false;
	    return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
	    unordered_map<char, int> freqPlate;
	    for(auto letter:licensePlate){
		    if(letter == ' ' || isdigit(letter))continue;
		    letter = tolower(letter);
		    freqPlate[letter]++;
	    }
	    string res = "";
	    for(auto &word:words){
		    if(!isPossible(freqPlate, word))continue;
		    if(res.empty() || res.size() > word.size())res = word;
	    }
	    return res;
    }
};
