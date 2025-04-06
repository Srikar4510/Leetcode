class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
         sort(nums.begin(),nums.end());
        vector<int> dp(n+1,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        
        for(int ind=1;ind<n;ind++){
            hash[ind]=ind;
            for(int prevInd=0;prevInd<ind;prevInd++){
                if(nums[ind]%nums[prevInd]==0&& 1+dp[prevInd]>dp[ind]){
                    dp[ind]=1+dp[prevInd];
                    hash[ind]=prevInd;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(lastIndex!=hash[lastIndex]){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};

