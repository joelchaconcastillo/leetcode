class Solution {
public:
    string solve(string &order, string &s){
	   unordered_map<char, int> positions;
	   for(int i = 0 ; i < order.size(); i++) positions[order[i]]=i;
	   for(auto letter:s)if(positions.count(letter)==0) positions[letter]=500;
	   sort(s.begin(), s.end(), [&](char a, char b){
			   return positions[a] < positions[b];
			   });
	   return s;
    }
    string solve2(string &order, string &s){
	   unordered_map<char, int> freq;
	   for(auto letter:s)freq[letter]++;
	   string res = "";
	   for(auto letter:order){
	        while(freq[letter]>0){
			res+=letter;
			freq[letter]--;
		}
	   }
	   for(auto letter:freq) while(letter.second--)res+=letter.first;
	   return res;
    }
    string customSortString(string order, string s) {
	    return solve2(order, s);
    }
};
