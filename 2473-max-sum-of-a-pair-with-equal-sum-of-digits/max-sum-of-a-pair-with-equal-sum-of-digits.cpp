class Solution {
private: 
   int Sum(int num){
    int digitSum =0;
    while(num>0){
        digitSum += num%10;
        num /= 10;
    } 
    return digitSum;
   }    
public:
//O(Nlogm),O(logm)
    int maximumSum(vector<int>& nums) {
        int result =-1;
        int digitSumMapping[82]={};
        for(int i=0;i<nums.size();i++){
            int digitSum = Sum(nums[i]);
            if(digitSumMapping[digitSum]!=0){
                result = max(result,digitSumMapping[digitSum]+nums[i]);
            }
            digitSumMapping[digitSum]= max(digitSumMapping[digitSum],nums[i]);
        }
        return result;
    }
};