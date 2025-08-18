class Solution {
public:
    bool areOccurrencesEqual(string s) {
         unordered_map<char, int>freq;
	 for(auto l:s)freq[l]++;
	 int target = freq[s.front()];
	 for(auto [l,count]:freq){
		 if(count!=target)return false;
	 }
	 return true;
    }
};
