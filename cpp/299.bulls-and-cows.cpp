class Solution {
public:
    string getHint(string secret, string guess) {
           int bulls = 0, cow = 0, n = secret.size();
	   unordered_map<char, int> freq1, freq2;
	   for(auto i:secret)freq1[i]++;
	   for(auto i:guess)freq2[i]++;
	   for(int i = 0 ; i < n; i++){
		   if(secret[i] == guess[i]){
			   bulls++;
			   freq1[secret[i]]--;
			   freq2[secret[i]]--;
		   }
	   }
	   for(auto [letter, cont]:freq1){
		   cow += min(cont, freq2[letter]);
	   }
	   return to_string(bulls)+"A"+to_string(cow)+"B";
    }
};
