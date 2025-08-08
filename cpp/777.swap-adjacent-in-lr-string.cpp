class Solution {
public:
	//xl -> lx
	//rx -> xr
	//RXXLRXRXL
	//XRLXXRRLX
    bool solve(string &start, string &result){
	    if(start.size() != result.size())return false;
	    int count_r = 0, n = start.size();
	    for(int i = 0 ; i < n; i++){
		    if(start[i] == 'R')count_r++;
		    if(result[i] == 'R')count_r--;
		    if(count_r >0 && (result[i]=='L'|| start[i]=='L'))return false;
		    if(count_r<0)return false;
	    }
	    if(count_r>0)return false;
	    int count_l = 0;
	    for(int i = n-1; i>=0; i--){
		    if(start[i]=='L')count_l++;
		    if(result[i]=='L')count_l--;
		    if(count_l>0 && (result[i]=='R' || start[i]=='R') )return false;
		    if(count_l<0)return false;
	    }
	    if(count_l>0)return false;
	    return true;
    }
    bool canTransform(string start, string result) {
	    return solve(start, result);
    }
};
