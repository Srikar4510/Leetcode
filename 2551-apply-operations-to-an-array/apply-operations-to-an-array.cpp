class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] *= 2;
                nums[i+1]=0;
            }
        }
        //traverse through array and bring all non zero elements to before 
        int nonZeroIndex=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[nonZeroIndex]=nums[i];
                nonZeroIndex++;

            }
        }
        //after all non zero elements are placed correctly 
        //make remaining elements of array zero
        while(nonZeroIndex<n){
            nums[nonZeroIndex]=0;
            nonZeroIndex++;
        }
        return nums;
    }
};