class Solution {
public:
    // int maximumCount(vector<int>& nums) {
    //     int n = nums.size();
    //     int pos=0,neg=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==0){
    //            continue;
    //         }
    //         else if(nums[i]<0){
    //             neg++;
    //         }
    //         else{
    //             pos++;
    //         }
    //     }
    //     return max(pos,neg);
    // }

    //If the first zero is located at index x, then there are x negative integers (from index 0 to x - 1). 
    //Similarly, if the last zero is at index y, there are N - y - 1 positive integers (from index y + 1 to N - 1).


    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};