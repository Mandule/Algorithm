class Solution {
public:
	vector<string> ans;
    vector<string> generateParenthesis(int n)
    {
		char str[n*2];
    	solve(str,0,0,0,n*2);
    	return ans;
    }
    void solve(char* str,int cur,int l,int r,int n)
    {
    	if(cur == n)
        {
    		string tmp;
    		for(int i=0;i<n;i++)
    			tmp+=str[i];
    		ans.push_back(tmp);
    		return;
    	}
    	else{
    		if(l < n/2)
            {
    			str [cur] = '(';
    			solve(str,cur+1,l+1,r,n);
    		}
    		if(r < l)
            {
    			str [cur] = ')';
    			solve(str,cur+1,l,r+1,n);
    		}
    	}
    }
};