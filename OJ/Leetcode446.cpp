class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        
        int num[A.size()];
        int ans=0;
        dfs(num,A,ans,0,A.size());
        return ans;
    }
    void dfs(int* num,vector<int>& A,int& ans,int cur,int n){
        if(cur==n){
            if(isOk(num,A))ans++;
            return;
        }
        num[cur] = 1;
        dfs(num,A,ans,cur+1,n);
        num[cur] = 0;
        dfs(num,A,ans,cur+1,n);
    }
    bool isOk(int* num,vector<int>& A){
        vector<int> tmp;
        for(int i=0;i<A.size();i++){
            if(num[i]==1) tmp.push_back(i);
        }
        if(tmp.size() < 3) return false;
        long long s=0;
        bool first=true;
        for(int i=1;i<tmp.size();i++){
            long long a = A[tmp[i]];
            long long b = A[tmp[i-1]];
            if(first) {s = b-a;first=false;}
            else if(s != b-a) return false;
        }
        return true;
    }
};



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long delta = (long)A[i] - A[j];
                if (delta > INT_MAX || delta < INT_MIN) continue;
                int diff = (int)delta;
                ++dp[i][diff];
                if (dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};