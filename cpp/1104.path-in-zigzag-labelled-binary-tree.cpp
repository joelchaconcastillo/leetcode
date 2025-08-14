class Solution {
public:
    // 2^(l-1)-1+ (  2^(l-1) -  (val/2-2^(l-1)))
    // 2(2^(l-1))-1-val/2+2^(l-1)
    // final equation
    // 3*(2^(l-1)) - 1 - val/2
    int get_parent(int level, int label){
	    if(level==0)return -1;
	    if(level<=1)return 1;
	    int top_nodes = (1<<(level-1));
	    return 3*top_nodes-1-label/2;
    }
    vector<int> pathInZigZagTree(int label) {
	    int L = log(label)/log(2);
	    vector<int> res;
	    while(label!=-1){
		    res.push_back(label);
		    label= get_parent(L, label);
		    L--;
	    }
	    reverse(res.begin(), res.end());
	    return res;
    }
};
