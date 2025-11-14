class Solution {
public:
    bool isArmstrong(int n) {
                int target = n;
        int k = to_string(n).size();
        int sum = 0;
        n=target;
        while(n){
            long long digit = n%10;
            sum += pow(digit, k);
            n/=10;
        }
        if(sum==target)return true;
        return false;	    
    }
};
