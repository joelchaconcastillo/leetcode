class Solution {
public:
    bool isLongPressedName(string name, string typed) {
	    int i=0, j=0;
	    int n = name.size(), m = typed.size();
	    char prevName = '0';
	    while(i<n && j < m){
		    if(name[i] == typed[j]){
			    prevName = name[i];
			    i++,j++;
		    }else if(prevName == typed[j])j++;
		    else return false;
	    }
	    while( j< m && typed[j] == prevName)j++;
	    return (i==n && j==m);
    }
};
