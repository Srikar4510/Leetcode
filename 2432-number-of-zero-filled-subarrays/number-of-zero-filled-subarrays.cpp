class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         long long count=0,ans=0;
         for(auto num:nums){
            if(num==0){
                count++;
                ans += count;
            }
            else{
                count =0;
            }
         }
        return ans;
     }
};