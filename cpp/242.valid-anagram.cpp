class Solution {
public:
    bool solve(string &s, string &t){
	unordered_map<char, int> counter1, counter2;
	for(auto i:s)counter1[i]++;
	for(auto i:t)counter2[i]++;
	return counter1 == counter2;

    }
    bool isAnagram(string s, string t) {
	    return solve(s, t);
    }
};
