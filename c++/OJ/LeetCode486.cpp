class Solution {
public:
    bool PredictTheWinner(vector<int>& nums){
    	return solve(nums,0,nums.size()-1) >= 0;
    }
    
    int solve(vector<int>& nums,int s,int t){
    	if(s==t) return nums[s];
    	return max(nums[s]-solve(nums,s+1,t),
                   nums[t]-solve(nums,s,t-1));
    }
};


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
       return canWin(nums, 0, 0, 1);
    }
    bool canWin(vector<int> nums, int sum1, int sum2, int player) {
        if (nums.empty()) return sum1 >= sum2;
        if (nums.size() == 1) {
            if (player == 1) return sum1 + nums[0] >= sum2;
            else if (player == 2) return sum2 + nums[0] > sum1;
        }
        vector<int> va = vector<int>(nums.begin() + 1, nums.end());
        vector<int> vb = vector<int>(nums.begin(), nums.end() - 1);
        if (player == 1) {
            return !canWin(va, sum1 + nums[0], sum2, 2) || !canWin(vb, sum1 + nums.back(), sum2, 2);
        } else if (player == 2) {
            return !canWin(va, sum1, sum2 + nums[0], 1) || !canWin(vb, sum1, sum2 + nums.back(), 1);
        }
    }
};


public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        if(nums == null || nums.length == 0) return false;
        int n = nums.length;
        int[][] dp = new int[n][n];
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                dp[i][j] = Math.max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] >= 0;
    }
}