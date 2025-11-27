class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();                         
        const long long INF = (long long)9e18;       

        vector<long long> minPref(k, INF);          

        minPref[0] = 0;                              
        long long prefix = 0;                        
        long long ans = LLONG_MIN;                  

        for (int i = 0; i < n; ++i) {                
            prefix += nums[i];                      
            int rem = (i + 1) % k;                  

            if (minPref[rem] != INF) {
                long long candidate = prefix - minPref[rem];
                if (candidate > ans) ans = candidate;
            }

            if (prefix < minPref[rem]) minPref[rem] = prefix;
        }

        return ans;                                 
    }
};
