class Solution {
public:
    bool check(vector<int>& nums) {
        int ctr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[(i+1)%nums.size()]<nums[i]) ctr++;
            if(ctr>1) return false;
        }
        return true;
    }
};