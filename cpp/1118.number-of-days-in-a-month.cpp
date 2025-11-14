class Solution {
public:
    int numberOfDays(int year, int month) {
	if(month==2){
		if( (year%4==0  && year % 100 !=0) || (year%400==0))
			return 29;
		return 28;
	}
        if(month <= 7){
		if(month%2==1)return 31;
		else return 30;
	}	
	if(month%2==0)return 31;
	return 30;
    }
};
