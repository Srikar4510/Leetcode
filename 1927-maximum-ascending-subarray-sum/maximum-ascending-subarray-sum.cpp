class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0],currSum = nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                currSum += nums[i+1];
            }    
            else{
                currSum = nums[i+1];
            }
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};