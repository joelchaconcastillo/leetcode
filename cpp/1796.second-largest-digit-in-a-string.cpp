class Solution {
public:
    int secondHighest(string s) {
	set<char> existent;
        for(auto letter:s){
		if(isdigit(letter))existent.insert(letter);
	}	
	if(existent.size() <2)return -1;
	return *prev(existent.end(),2) - '0';
    }
};
