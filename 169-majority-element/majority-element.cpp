class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //int n = nums.size();

        //Brute Force Approach T.C->O(N^2) SC->O(1)
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[i]==nums[j])
        //          count++;
        //     }
        //     if(count>n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //SORTING APPROACH T.C->O(logn) SC->O(1)
        
            // sort(begin(nums),end(nums));
            // return nums[n/2];

        //Moore voting  algorithm

        int lead_gang = INT_MIN;
        int totalMem = 0;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(totalMem==0){
                totalMem = 1;
                lead_gang = nums[i];
            }
            else if(nums[i]==lead_gang){
                totalMem++;
            }
            else{
                totalMem--;
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==lead_gang){
                cnt++;
            }
        }
        
        if(cnt>n/2){
            return lead_gang;
        }
        else{
            return -1;
        }
    }
};