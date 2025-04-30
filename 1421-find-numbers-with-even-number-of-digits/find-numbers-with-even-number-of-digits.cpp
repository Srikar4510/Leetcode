class Solution {
public:
    // int countDigits(int num){
    //     int cnt =0;
    //     while(num){
    //         num = num/10;
    //         cnt++;
    //     }
    //     return cnt;
    // }
    // int findNumbers(vector<int>& nums) {
    //     int ans =0,n=nums.size();
    //     for(int i=0;i<n;i++){
    //         if(countDigits(nums[i]) % 2==0){
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }

       int findNumbers(vector<int>& nums) {
           int ans = 0,n = nums.size();
           for(int i=0;i<n;i++){
             int length = to_string(nums[i]).length();

             if(length % 2 ==0){
                ans++;
             }
           }
           return ans;
    }
};