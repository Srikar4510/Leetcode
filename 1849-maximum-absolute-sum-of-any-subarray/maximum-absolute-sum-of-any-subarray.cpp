class Solution {
public:
    // int maxAbsoluteSum(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxsum=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int sum =0;
    //         for(int j=i;j<n;j++){
    //             sum += nums[j];
    //             maxsum = max(maxsum,abs(sum));
    //         }
    //     }
    //     return maxsum;
    // }

    int maxAbsoluteSum(vector<int>& nums) {
       int minPrefixSum = 0,maxPrefixSum=0;
       int prefixSum;
       for(int i=0;i<nums.size();i++){
        prefixSum += nums[i];
        minPrefixSum = min(minPrefixSum,prefixSum);
        maxPrefixSum = max(maxPrefixSum,prefixSum);

        }
        return maxPrefixSum - minPrefixSum;
    }
};