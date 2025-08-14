class Solution {
public:
   //  W * L = area
   //  L = sqrt(area)
	//time: O(sqrt(n))
	//space: O(1)
    vector<int> constructRectangle(int area) {
	    int W = sqrt(area);//initialization
	    while(area%W)W--; //decrease it until we find a divisible
	    return {area/W, W};
//	    int L=area, W=1;
//	    for(int l = 1; l <= area; l++){
//		    if(area%l!=0)continue;
//		    int w = area/l;
//		    if( w > l)continue;
//		    if(abs(L-W) > abs(l-w)) L=l, W=w;
//	    }
//	    return {L, W};
    }
};
