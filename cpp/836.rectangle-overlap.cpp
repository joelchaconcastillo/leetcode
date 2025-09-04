class Solution {
public:
    
    bool solve1(vector<int>& rec1, vector<int>& rec2) {
	    int width = min(rec1[2], rec2[2])-max(rec1[0], rec2[0]);
	    int height = min(rec1[3], rec2[3])-max(rec1[1], rec2[1]);
	    return width > 0 && height>0;
    }
    bool solve2(vector<int>& rec1, vector<int>& rec2) {
	    bool left = rec2[2] <= rec1[0];
	    bool top = rec2[1] >= rec1[3];
	    bool bottom = rec2[3] <= rec1[1]; 
	    bool right = rec2[0] >= rec1[2];
	    return !( left || top || right || bottom);
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
	    return solve2(rec1, rec2);
	    return solve1(rec1, rec2);
    }
};
