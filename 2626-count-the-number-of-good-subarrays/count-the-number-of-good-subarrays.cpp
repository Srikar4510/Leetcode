class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int left=0,pairCount = 0;
        long long ans =0;

        for(int right=0;right<n;right++){
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            while(pairCount >= k){
                ans += (n - right);
                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }
            
        }
        return ans;
    }
};