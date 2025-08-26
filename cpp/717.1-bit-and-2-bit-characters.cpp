class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
         int n = bits.size(), i=0;
	 while(i+1<n){
		 if(bits[i]==0) i++;
		 else i+=2;
	 }
	 return i==n-1;
    }
};
