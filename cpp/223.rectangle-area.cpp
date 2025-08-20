class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int down_x = max(ax1, bx1);
        int down_y = max(ay1, by1);
        int up_x = min(bx2, ax2);
        int up_y = min(by2, ay2);	
	int area_intersection = max(0, up_x-down_x)*max(0, up_y-down_y);
	int area1 = max(0, ax2-ax1)*max(0, ay2-ay1);
	int area2 = max(0, bx2-bx1)*max(0, by2-by1);
	return area1+area2-area_intersection;
    }
};
