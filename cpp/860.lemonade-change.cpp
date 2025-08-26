class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
	 int n = bills.size();
	 vector<int> current(21,0);
	 vector<int> coins = {20,10,5};
         for(int i = 0 ; i < n ;i++){
		 int bill = bills[i];
		 int change = bill-5;
		 for(auto coin:coins){
			 while(current[coin]>0 && change-coin >=0){
				 change-=coin;
				 current[coin]--;
			 }
		 }
		 if(change!=0)return false;
		 current[bill]++;
	 }	 
	 return true;
    }
};
