class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
	int cap=0, low=0;
        for(auto letter:word){
		if(!islower(letter))cap++;
		else low++;
	}	
	if(cap==n)return true;
	if(low==n)return true;
	if(!islower(word.front()) && low==n-1)return true;
	return false;
    }
};
