class Solution {
public:
    bool solve(vector<int> &y){
	 int n = y.size();
	 vector<int> x1(n);
	 x1.back()=0;
	 for(int i = n-2; i>=0; i--){
	    x1[i] = x1[i+1]^y[i]; 
	 }
	 bool hassol1 = true;
	 for(int i = 0 ; i < n; i++){
	    if( (x1[i]^x1[(i+1)%n]) != y[i]) hassol1=false;
	 }
	 return hassol1;
    }
    bool doesValidArrayExist(vector<int>& derived) {
	 return solve(derived);
    }
};
/*xor?
 f[i] f[i+1] y[i]
   ?     *     t
   1     1     0   
   1     0     1  
   0     1     1  
   0     0     0


 y[i] = f[i] ^ f[i+1]
 y -->  1 1 0
 f -->  0 1 0

 Input: derived = [1,1,0]
 Output: true
 Explanation: A valid original array that gives derived is [0,1,0].
 derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
 derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
 derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0

Example 2:

   1 1
   0 1
Input: derived = [1,1]

Output: true
Explanation: A valid original array that gives derived is [0,1].
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
Example 3:


   1 0
   1 0
Input: derived = [1,0]
Output: false
Explanation: There is no valid original array that gives derived.



 * */
