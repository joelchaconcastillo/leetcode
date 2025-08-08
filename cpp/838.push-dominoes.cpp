class Solution {
public:
    string solve(string &dominoes){
	    int n = dominoes.size();
	    int impossible=-10000;
	    vector<int> dpL(n,impossible), dpR(n,impossible);
	    int lastR = impossible, lastL=impossible;
	    for(int i = 0 ;i  < n; i++){
		    if(dominoes[i]=='R'){
			    lastR=i;
		    }else if(dominoes[i]=='L'){
			    lastR=impossible;
		    }
		    dpR[i]=lastR;
	    }
	    for(int i = n-1 ;i >=0; i--){
		    if(dominoes[i]=='L'){
			    lastL=i;
		    }else if(dominoes[i]=='R'){
			    lastL=impossible;
		    }

		    dpL[i]=lastL;
	    }
	    string res ="";
	    for(int i = 0 ;i < n ;i++){
		    int deltaL = abs(i-dpL[i]);
		    int deltaR = abs(i-dpR[i]);
		    if(dominoes[i] != '.'){
			    res += dominoes[i];
			    continue;
		    }
		    if(deltaL < deltaR) res+='L';
		    else if(deltaL>deltaR)res+='R';
		    else res+='.';
	    }
	    return res;
    }
    string solve2(string &dominoes){
	    int n = dominoes.size();
	    pair<char, int> lastSeen;
	    auto res = dominoes;
	    int i = 0;
	    while(i<n && dominoes[i]=='.')i++;
	    if(i<n && dominoes[i]=='L'){
		    while(i>=0)res[i--]='L';
	    }
	    int j = n-1;
	    while(j>=0 && dominoes[j]=='.')j--;
	    if(j>=0 && dominoes[j]=='R'){
		    while(j<n) res[j++]='R';
	    }
	    for(int i = 0 ;i  < n; i++){
		    if(dominoes[i]=='L'){
			    if(lastSeen.first == 'R'){
				    int a = lastSeen.second;
				    int b = i;
				    while(a<b){
					    res[a++]='R';
					    res[b--]='L';
				    }
			    }else if(lastSeen.first == 'L'){
				    int j = lastSeen.second;
				    while(j<i)res[j++]='L';
			    }
			    lastSeen = {'L',i};
		    }
		    else if(dominoes[i]=='R'){
			    if(lastSeen.first == 'R'){
				    int j = lastSeen.second;
				    while(j<i) res[j++]='R';
			    }
			    lastSeen = {'R',i};
		    }
	    }
	    return res;
    }
    string pushDominoes(string dominoes) {
	    return solve2(dominoes);
	    return solve(dominoes);
    }
};
/*
 
     0 1 2 3 4 5 6 7 8 9  10 11 12 23
   " . L . R . . . L R .  .  L  .  ."
     1 1 . R 7 7 7 7 R 11 11 11 .  .
     . L . R 3 3 3 L R 8  8  L  .  .
     L L . R R . L L R R  L  L  .  .
   "LL.RR.LLRRLL.."
 *
 */
