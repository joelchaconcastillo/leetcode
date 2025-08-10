class Solution {
public:
    int findClosest(int x, int y, int z) {
        int abs1=abs(x-z), abs2=abs(y-z);
        if(abs1<abs2)return 1;
        else if(abs1>abs2)return 2;	
	return 0;
    }
};
