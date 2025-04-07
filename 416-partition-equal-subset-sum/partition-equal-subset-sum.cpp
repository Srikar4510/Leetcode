class Solution {
public:
    bool subSetSum(int target,vector<int>& nums){
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));

        for(int i=0;i<n;i++) dp[i][0]=true;

        if (nums[0] <= target) dp[0][nums[0]]=true;

        for(int ind=1;ind<n;ind++){
            for(int tar=1;tar<=target;tar++){
                bool notTake = dp[ind-1][tar];
                bool take = false;
                if(tar>=nums[ind]){
                    take = dp[ind-1][tar-nums[ind]];
                }
                dp[ind][tar]= take|notTake;
            }
            
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n = nums.size();
        if(n==1) return false;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum % 2)
         return false;
        return (subSetSum(sum/2,nums));
    }
};