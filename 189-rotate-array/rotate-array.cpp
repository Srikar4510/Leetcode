class Solution {
public:
//Reverse the first n-k elements of the array.
//Reverse the last k elements of the array
//Reverse the whole array.
    void reverse(vector<int> &nums,int start,int end){
         while(start<=end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end]=temp;
            start++;
            end--;
         }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};