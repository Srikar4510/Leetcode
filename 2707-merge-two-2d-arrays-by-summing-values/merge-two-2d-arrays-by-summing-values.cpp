class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left =0,right=0;

        vector<vector<int>> mergedArray;
        while(left<n1 && right<n2){
            if(nums1[left][0]==nums2[right][0]){
                mergedArray.push_back({nums1[left][0],nums1[left][1]+nums2[right][1]});
                left++;
                right++;
            }
            else if(nums1[left][0]<nums2[right][0]){
                mergedArray.push_back(nums1[left]);
                left++;
              
            }
            else{
                mergedArray.push_back(nums2[right]);
                right++;
            }
        }

        while(left<n1){
            mergedArray.push_back(nums1[left]);
            left++;
        } 

        while(right<n2){
            mergedArray.push_back(nums2[right]);
            right++;
        }

        return mergedArray;
    }
};