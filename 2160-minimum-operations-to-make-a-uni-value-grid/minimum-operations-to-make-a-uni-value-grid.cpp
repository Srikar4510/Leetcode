class Solution {
public:
    //all numbers in the grid must have the same remainder when divided by x
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }

        int n = nums.size();
        //partially sorts the element that will be at nth element
        //time complexity is O(n) compared to sort function O(NLOGN)
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());

        int median = nums[n/2];
        int ans =0;
        for(int num:nums){
            if(num%x != median%x){
                return -1;
            }
            else{
               ans += abs(median-num)/x;
            }
        }
        return ans;
    }
};