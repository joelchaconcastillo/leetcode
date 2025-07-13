class Solution {
public:
    int solve(vector<vector<int> > &boxTypes, int truckSize){
	    for(auto &item:boxTypes){
		    swap(item[0], item[1]); //price, amount(units)
	    }
	    sort(boxTypes.begin(), boxTypes.end());
	    int res = 0, n = boxTypes.size();
	    for(int i = n-1; i >=0; i--){
		    int units = min(truckSize, boxTypes[i][1]);
		    truckSize -=units;
		    res += boxTypes[i][0]*units;
	    }
	    return res;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        return solve(boxTypes, truckSize);	    
    }
};

