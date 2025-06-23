class Solution {
public:
    bool solve(string &st){
	 unordered_map<char, int> freq;
	 for(auto letter:st)freq[letter]++;
	 int count_even=0, count_odd=0;
	 for(auto [letter, count]:freq){
		 if(count%2==0)count_even++;
		 else count_odd++;
	 }
	 if(count_odd>1)return false;
	 return true;
    }
    bool canPermutePalindrome(string s) {
	    return solve(s);
    }
};
