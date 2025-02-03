class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int n = nums.size();
         int maxLength =1,incLength =1,decLength =1;
         for(int i=0;i<n-1;i++){
             if(nums[i]<nums[i+1]){
                incLength++;
                decLength =1;
             }    
             else if(nums[i]>nums[i+1]){
                decLength++;
                incLength=1;
             }
             else{
                incLength=1;
                decLength=1;
             }

             maxLength = max(maxLength,max(incLength,decLength));
         }
         return maxLength;
    }
};