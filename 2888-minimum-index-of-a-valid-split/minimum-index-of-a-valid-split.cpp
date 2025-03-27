class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int totalMem =0,lead_gang = INT_MIN,n = nums.size();
        for(int i=0;i<n;i++){
            if(totalMem==0){
                totalMem=1;
                lead_gang=nums[i];
            }
            else if(nums[i]==lead_gang){
                totalMem++;
            }
            else{
                totalMem--;
            }
        }
        
        int totalCount =0;
        for(int num:nums){
            if(num==lead_gang){
                totalCount++;
            }
        }
        
        totalMem=0;
        for(int i=0;i<n;i++){
            if(nums[i]==lead_gang){
              totalMem++;
            }

            int remainingMem = totalCount-totalMem;
            if(totalMem*2 > i+1 && remainingMem*2 > n-i-1){
                return i;
            }
        }
        return -1;
    }
};