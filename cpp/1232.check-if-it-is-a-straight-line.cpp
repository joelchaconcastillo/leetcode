class Solution {
public:
    pair<int, int> factors(vector<int> &a, vector<int> &b){
	    int delta_x = a[0]-b[0];
	    int delta_y = a[1]-b[1];
	    if(delta_y == 0 && delta_x ==0)return {0,0};
	    if(delta_y==0)return {1, 0};
	    int _gcd = __gcd(delta_x, delta_y);
	    delta_x/=_gcd;
	    delta_y/=_gcd;
	    if(delta_y < 0) delta_x = -delta_x, delta_y = -delta_y;
	    return {delta_x, delta_y};
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
	    auto reference = factors(coordinates[0], coordinates[1]);
	    for(int i = 1; i < coordinates.size(); i++){
		    if(coordinates[0] == coordinates[i])continue;
		    auto check = factors(coordinates[0], coordinates[i]);
		    if(reference!=check)return false;
	    }
	    return true;
    }
};
