class Solution {
public:
    string removeVowels(string s) {
         string res = "";
	 for(auto i:s){
		 if(i== 'a')continue;
		 if(i== 'e')continue;
		 if(i== 'i')continue;
		 if(i== 'o')continue;
		 if(i== 'u')continue;
		 res += i;
	 }
	 return res;
    }
};
