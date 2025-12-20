/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int solve1(int n) {
	    if(n==1)return 0;
        vector<int> inDegree(n, 0), outDegree(n, 0); 
	for(int i = 0 ; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(knows(i, j)) inDegree[j]++, outDegree[i]++;
			if(knows(j, i)) inDegree[i]++, outDegree[j]++;
		}
	}
	for(int i = 0 ; i < n; i++)if(inDegree[i]==n-1 && outDegree[i]==0)return i;
	return -1;
    }
    int solve2(int n) {
	    int pivot = 0;
	    for(int i = 0 ;i  < n; i++){
		    if(knows(pivot, i)){
			    pivot = i;
		    }
	    }
	    int inDeg=0, outDeg=0;
	    for(int i = 0 ; i < n ;i++){
		    if(i==pivot)continue;
		    if(knows(pivot, i)) return -1;
		    if(!knows(i, pivot)) return -1;
	    }
	    return pivot;
    }
    int findCelebrity(int n) {
	    return solve2(n);
	    return solve1(n);
    }
};
