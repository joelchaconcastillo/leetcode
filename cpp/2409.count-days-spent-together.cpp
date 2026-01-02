class Solution {
public:
    vector<int> markDays(string &arrive, string &leave, vector<int> &monthFreq, vector<int> &daysMonth){
	    vector<int> days(366,0);
	    int startMonth = stoi(arrive.substr(0,2));
	    int endMonth = stoi(leave.substr(0,2));
	    int startDay = stoi(arrive.substr(3,2));
	    int endDay = stoi(leave.substr(3,2));
	    int currentDay = monthFreq[startMonth]+startDay;
	    while(currentDay <= monthFreq[endMonth]+endDay){
		    days[currentDay]++;
		    currentDay++;
	    }
	    return days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
	    vector<int> daysMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	    vector<int> monthFreq(daysMonth.size()+1);
	    int totalM = 0;
	    for(int i = 1 ; i <= 12; i++){
		    monthFreq[i] = totalM;
		    totalM += daysMonth[i-1];
	    }
	    auto alice = markDays(arriveAlice, leaveAlice, monthFreq, daysMonth);
	    auto bob = markDays(arriveBob, leaveBob, monthFreq, daysMonth);
	    int res = 0;
	    for(int i = 0 ; i < alice.size(); i++){
		    if(alice[i] && bob[i])res++;
	    }
	    return res;
    }
};
