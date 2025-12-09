class Solution {
public:
    vector<string> split(string &date){
	    date +=" ";
	    string current = "";
	    vector<string> res;
	    for(auto i:date){
		   if(i==' '){
			 res.push_back(current);
			 current = "";
		   }else current += i;
	    }
	    return res;
    }
    string reformatDate(string date) {
	    auto fields = split(date);
	    //check day...
	    int day = stoi(fields[0]);
	    unordered_map<string, string> month = {
		    {"Jan", "01"},
		    {"Feb", "02"},
		    {"Mar", "03"},
		    {"Apr", "04"},
		    {"May", "05"},
		    {"Jun", "06"},
		    {"Jul", "07"},
		    {"Aug", "08"},
		    {"Sep", "09"},
		    {"Oct", "10"},
		    {"Nov", "11"},
		    {"Dec", "12"}
	    };
	    string st_day = "";
	    if(day < 10) st_day = "0"+to_string(day);
	    else st_day = to_string(day);

	    return  fields.back() + "-" + month[fields[1]] + "-" + st_day;
    }
};
