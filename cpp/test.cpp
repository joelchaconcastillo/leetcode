#include <bits/stdc++.h>
using namespace std;
bool __gcd(int x, int y, int target){
   if(x+y == target)return true;
   if(y==0) return false;
   return __gcd(y, x%y);
}
int solve(int x, int y, int target){
    return __gcd(x, y, target);
}
int main(){
   int x = 3, y = 5, target = 4;
   cin >> x >> y >> target;
   cout << solve(x, y, target)<<endl;
   return 0;
}
/*
  1) fill one
  2) transfer 
  3) empty one

 Input: x = 3, y = 5, target = 4   mcm 15  gcd 
 Output: true

 Input: x = 2, y = 6, target = 5
 Output: false
     2    6
     -
     0    6
     2    4
     -
     2    6

 

 Input: x = 1, y = 2, target = 3
 Output: true
 ---
 fill     0 5
 pour     3 2
 empty    0 2
 transfer 2 0
 /
 fill     2 5
 pour     3 4
 empty    0 4
 Fill the 5-liter jug (0, 5).
Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
Empty the 3-liter jug (0, 2).
Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).
Fill the 5-liter jug again (2, 5).
Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).
Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).


 * */
