class Solution {
public:
    string MostSimilar(string color){
	    string res = "";
	    int maxV = -1;
	    int num = stoi(color, NULL, 16), minDiff = INT_MAX;
	    for(int i = 0 ; i < 16; i++){
		    int diff = (i*17-num)*(i*17-num);
		    if(diff < minDiff){
			minDiff=diff;
			maxV = i;
		    }
	    }
	    if(maxV > 9){
		    res += 'a'+maxV-10;
	    }
	    else{
		    res = '0'+maxV;
	    }
	    res = res+res;
	    return res;
    }
    string solve(string &c){
	    string res = "#";
	    for(int i = 1 ;i < 6; i+=2){
		    res += MostSimilar(c.substr(i,2));
	    }
	    return res;
    }
    string similarRGB(string color) {
	    return solve(color);
    }
};
