typedef long long ll;

class Solution {
public:
    vector< vector<int> > ans;
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            towSum(nums,i+1,nums.size()-1,nums[i]);            
        }
        return ans;
    }
    void towSum(vector<int> nums,int s,int t,int Sum){
        while(s<t){
            if(nums[s]+nums[t]+Sum == 0){
                vector<int> tmp;
                tmp.push_back(Sum);
                tmp.push_back(nums[s]);
                tmp.push_back(nums[t]);
                ans.push_back(tmp);
                s++;
                t--;
                while(s<t && nums[s] == nums[s-1]) s++;
                while(s<t && nums[t] == nums[t+1]) t--;
            }
            else if(nums[s]+nums[t]+Sum >0)
                t--;
            else
                s++;
        }
    }
};