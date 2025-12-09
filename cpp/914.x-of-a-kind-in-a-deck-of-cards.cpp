class Solution {
public:
    bool solve1(vector<int>& deck) {
         unordered_map<int ,int> freq;
         for(auto i:deck)freq[i]++;
         unordered_set<int> counts;
	 if(freq[deck.front()]==1)return false;
	 int n = deck.size();
	 for(int i = n-1; i >= 1; i--){
	   if(n%i!=0)continue;
	   int group_sz = n/i;
	   bool can_be_splitted = true;
           for(auto [val, cont]:freq){// this is very naive
		   if(cont%group_sz != 0){
			   can_be_splitted=false;
			   break;
		   }
	   }
	   if(can_be_splitted)return true;
	 }
	 return false;
    }
    bool solve2(vector<int>& deck) {
	 int n = deck.size();
	 sort(deck.begin(), deck.end());
	 for(int i = 2; i <= n; i++){
		 // i*k = n,  k = n/i
		 if(n%i!=0)continue;
		 // 0 1 2 3 4 5 6 7 
		 // _ _ _ _ _ _ _ _
		 // x 0 x 0 x 0 x 0
		 //     l
		 //       i
		 unordered_set<int> window;
		 bool all_good = true;
		 int l = 0;
		 for(int j = 0; j < n; j++){
			 window.insert(deck[j]);
			 if((j-l+1)%i==0){
			     if(window.size() > 1){
				     all_good=false;
				     break;
			     }
			     l=j+1;
			     window.clear();
			 }
		 }
		 if(all_good)return true;
	 }
	 return false;
    }
    bool solve3(vector<int>& deck) {
	    unordered_map<int, int> freq;
	    for(auto i:deck)freq[i]++;
	    int gcd_val = freq.begin()->second;
	    for(auto [val, cont]:freq){
		gcd_val = __gcd(gcd_val, cont);
	    }
	    return gcd_val >=2;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
	 return solve3(deck);
	 return solve2(deck);
	 return solve1(deck);
    }
};
