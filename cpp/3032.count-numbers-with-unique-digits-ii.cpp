class Solution {
public:
    int numberCount(int a, int b) {
	int cont = 0;
        for(int i = a; i <=b; i++){
		string st = to_string(i);
		unordered_set<char> all(st.begin(), st.end());
		if(all.size() == st.size())cont++;
	}		
	return cont;
    }
};
