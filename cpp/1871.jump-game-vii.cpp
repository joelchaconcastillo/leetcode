class Solution {
public:
    vector<int> FTree;
    void FT_add(int index, int val){
	    while(index < FTree.size()){
		    FTree[index]+=val;
		    index += (index&(-index));
	    }
    } 
    int FT_query(int index){
	    if(index <=0) return 0;
	    if(index >= FTree.size()) return 0;
	    int sum = 0;
	    for(; index>0; index -= index&(-index))
		    sum += FTree[index];
	    return sum;
    }
    int FT_query(int left, int right){
	    return FT_query(right)-FT_query(left-1);
    }
    bool solve1(string s, int minJump, int maxJump) {
	  int n = s.size();
	  FTree.assign(n+2, 0);
	  FT_add(1,1);
	  for(int i = 0 ; i < n; i++){
		  if(s[i]=='1')continue;
		  int a = i+1-maxJump, b = i+1-minJump;
		  if(FT_query(a, b)) FT_add(i+1, 1);
	  }
	  return FT_query(n,n);
    }
    bool solve2(string s, int minJump, int maxJump) {
	    int n = s.size();
	    vector<int> prefix(n+1, 0);
	    vector<bool> dp(n,false);
	    dp[0]=true;
	    prefix[1]=1;
	    for(int i = 1; i < n; i++){
		    if(s[i]=='0'){
		        int left = max(0,i-maxJump);
		        int right = i-minJump;
		        if(right>=0 && prefix[right+1]-prefix[left]>0) dp[i]=true;
		    }
		    prefix[i+1]=prefix[i]+dp[i];
	    }
	    return dp.back();
    }
    bool canReach(string s, int minJump, int maxJump) {
	    return solve2(s, minJump, maxJump);
	    return solve1(s, minJump, maxJump);
    }
};
