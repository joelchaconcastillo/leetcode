class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
	  unordered_set<int>marked;
	  for(long long i = 1; i<=bound; i*=x){
		  for(long long j = 1; i+j<=bound; j*=y){
			  marked.insert(i+j);
			  if(y==1)break;
		  }
		  if(x==1)break;
	  }
          vector<int> res(marked.begin(), marked.end());
          return res;	  
    }
};
