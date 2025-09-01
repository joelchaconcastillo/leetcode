class Solution {
public:
    bool checkInclusion(string s1, string s2) {
	 vector<int> freq1(50,0), freq2(50,0);
	 for(auto letter:s1)freq1[letter-'a']++;
	 int l = 0, n = s2.size();
	 for(int i = 0 ; i < n; i++){
		 freq2[s2[i]-'a']++;
		 while(l<=i && freq1[s2[i]-'a'] < freq2[s2[i]-'a']){
			 freq2[s2[l]-'a']--;
			 l++;
		 }
		 if(freq1 == freq2)return true;
	 }
	 return false;
    }
};
                     
//s1 = "ab", s2 = "eidbaooo"
//                    l
//                     i
// a:1
// b:1
//
//Input: s1 = "ab", s2 = "eidboaoo"
// a:1                        i
// b:1                       l
