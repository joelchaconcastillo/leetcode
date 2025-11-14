class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
	vector<int> even(3), odd(3);
	for(auto i:a) if(__builtin_popcount(i)%2==0)even[0]++;else odd[0]++;
	for(auto i:b) if(__builtin_popcount(i)%2==0)even[1]++;else odd[1]++;
	for(auto i:c) if(__builtin_popcount(i)%2==0)even[2]++;else odd[2]++;
        int cont = 0;
	cont += even[0]*even[1]*even[2];
	cont += odd[0]*odd[1]*even[2];
	cont += odd[0]*even[1]*odd[2];
	cont += even[0]*odd[1]*odd[2];
	return cont;
    }
};
