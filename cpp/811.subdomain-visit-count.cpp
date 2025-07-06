class Solution {
public:
    vector<string> solve(vector<string> &cpdomains){
	    unordered_map<string, int> freq;
	    for(auto domain:cpdomains){
		    istringstream stm(domain);
		    int rep;
		    string full_domain;
		    stm >> rep;
		    stm >> full_domain;
		    int n = full_domain.size();
		    freq[full_domain] +=rep;
		    for(int i = 0 ; i < full_domain.size(); i++){
			   if(full_domain[i]=='.'){
				   freq[full_domain.substr(i+1)]+=rep;
			   }
		    }
	    }
	    vector<string> res;
	    for(auto [dom, rep]:freq){
		    res.push_back(to_string(rep)+" "+dom);
	    }
	    return res;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
	    return solve(cpdomains);
    }
};
