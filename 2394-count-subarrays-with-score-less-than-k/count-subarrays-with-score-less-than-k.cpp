class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res =0,sum=0;

        for(int i=0,j=0;j<n;j++){
            sum += nums[j];

            while(i<=j && sum*(j-i+1) >= k){
                sum -= nums[i];
                i++;
            }

            res += (j-i+1);
        }
        return res;
    }
};