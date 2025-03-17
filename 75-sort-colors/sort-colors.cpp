class Solution {
public:
    void sortColors(vector<int>& nums) {
        //0->LOW-1 => 0
        //low to mid-1 =>1
        //mid to high =>UNSORTED
        //high+1 to n-1 => 2
        int n = nums.size();
        int low=0,mid =0,high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};