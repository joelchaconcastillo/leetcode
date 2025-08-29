class Solution {
public:
    int get_pow(int x){
	    int cont = 0;
	    while(x!=1){
		    if(x%2==0) x/=2;
		    else x = (x*3)+1;
		    cont++;
	    }
	    return cont;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > path;
        for(int i = lo; i<=hi; i++){
		path.push_back({get_pow(i),i});
	}	
	sort(path.begin(), path.end());
	return path[k-1].second;
    }
};
