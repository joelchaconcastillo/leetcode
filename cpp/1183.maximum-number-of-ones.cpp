class Solution {
public:
    int solve(int width, int height, int sideLength, int maxOnes){
	    map<tuple<int, int> , int>freq;
	    for(int i = 0 ; i < width; i++){
		    for(int j = 0 ; j < height; j++){
			    freq[{i%sideLength, j%sideLength}]++;
		    }
	    }
	    priority_queue<tuple<int, int, int>>pq;
	    for(auto ii:freq){
		    auto [row, col] = ii.first;
		    pq.push({ii.second, row, col});
	    }
	    int res = 0, selected=0;
	    while(!pq.empty() && selected < maxOnes){
		    auto [ones, row, col] =  pq.top(); pq.pop();
		    res +=ones;
		    selected++;
	    }
	    return res;
    }
    int solve_optimized(int width, int height, int sideLength, int maxOnes){
	   int res = maxOnes * (height/sideLength)*(width/sideLength);
	   int remain = maxOnes;
	   int cnt1 = min( (height%sideLength)*(width%sideLength), remain);//no full squares
	   res += ((height/sideLength)+(width/sideLength)+1)*cnt1;
	   remain -= cnt1;
	   if( height/sideLength > width/sideLength){
		   int cnt2 = min(((width%sideLength)*sideLength)-((height%sideLength)*(width%sideLength)),remain);
		   res += (height/sideLength)*cnt2;
		   remain -=cnt2;
		   int cnt3 = min(((height%sideLength)*sideLength) - ((height%sideLength)*(width%sideLength)), remain);
		   res += (width/sideLength)*cnt3;
		   remain -= cnt3;
	   }else{
		   int cnt2 = min(((height%sideLength)*sideLength)- ((height%sideLength)*(width%sideLength)),remain);
		   res += (width/sideLength)*cnt2;
		   remain -=cnt2;
		   int cnt3 = min(((width%sideLength)*sideLength)-((height%sideLength)*(width%sideLength)), remain);
		   res += (height/sideLength)*cnt3;
		   remain -=cnt3;
	   }
	   return res;
    }
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
	    return solve_optimized(width, height, sideLength, maxOnes);
	    return solve(width, height, sideLength, maxOnes);
    }
};
