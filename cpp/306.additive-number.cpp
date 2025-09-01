class Solution {
public:
    string addStrings(const string &a, const string &b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool checkSum(string &num, int idx1, int idx2, int idx3, int i){
        string dig3 = num.substr(idx3, idx2 - idx3);
        string dig2 = num.substr(idx2, idx1 - idx2);
        string dig1 = num.substr(idx1, i - idx1);
	long long sum = stoll(dig2)+stoll(dig3);
	return sum == stoll(dig1);
//        string sum = addStrings(dig3, dig2);
//        return (sum == dig1);
    }

    bool helper(string &num, int idx1, int idx2, int idx3, int count){
        if (idx1 == num.size()){
            return count >= 3;
        }
        for (int i = idx1; i < num.size(); i++){
	    if(i-idx1>17)break;//prune!!
            if (num[idx1] == '0' && i > idx1) break;

            if (idx3 == -1 || idx2 == -1){
                if (helper(num, i + 1, idx1, idx2, count + 1)) return true;
            }
            else if (checkSum(num, idx1, idx2, idx3, i + 1)){
                if (helper(num, i + 1, idx1, idx2, count + 1)) return true;
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        return helper(num, 0, -1, -1, 0);
    }
};

