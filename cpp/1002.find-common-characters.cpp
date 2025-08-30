class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<string> res;
       vector<int> freq(100);
       for(auto letter:words[0])freq[letter-'a']++;
       for(auto word:words){
           vector<int> current_freq(100);
          for(auto letter:word) current_freq[letter-'a']++;
	  for(int i = 0 ; i < 100; i++){
		  freq[i] = min(freq[i], current_freq[i]);
	  }
       }
       for(char letter = 'a'; letter <='z'; letter++){
	       while(freq[letter-'a']--)res.push_back(string(1, letter));
       }
       return res;
    }
};
