class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxValue = *max_element(nums.begin(),nums.end());
        long long res =0;
        int left =0,n = nums.size(),count =0;

        for(int right =0;right<n;right++){
            if(nums[right]==maxValue){
               count++;
            }

            while(count==k){
                if(nums[left]==maxValue){
                    count--;
                }
                left++;
            }
            res += left;
        }
        return res;
    }
};