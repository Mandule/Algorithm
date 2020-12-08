class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int open[s.size()],close[s.size()];
        int n=0,m=0;
        for(int i=0;i<s.size();i++){
        	if(s[i] == '(') open[n++] = i;
        	if(s[i] == ')') open[m++] = i;
        }
        
    }
    bool exist(vector<string>& ans,string s){
    	for(int i=0;i<ans.size();i++){
    		if(ans[i] == s) return true;
    	}
    	return false;
    }
	bool isValid(string s){
		int open=0,close=0;
		for(int i=0;i<s.size();i++){
			if(s[i] == '(') open++;
			if(s[i] == ')') close++;
			if(close>open) return false;
 		}
 		return true;
	}
};