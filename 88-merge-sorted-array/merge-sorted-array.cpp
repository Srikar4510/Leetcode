class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //    for(int i=0;i<n;i++){
    //     nums1[m+i]=nums2[i];
    //    }
    //    sort(begin(nums1),end(nums1));
    // }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int left =0,right=0;
      vector<int> ans;
      while(left<m && right<n){
        if(nums1[left]==nums2[right]){
            ans.push_back(nums1[left]);
            ans.push_back(nums2[right]);
            left++;
            right++;
        }
        else if(nums1[left]<nums2[right]){
            ans.push_back(nums1[left]);
            left++;
        }
        else{
            ans.push_back(nums2[right]);
            right++;
        }
      }

      while(left<m){
        ans.push_back(nums1[left]);
        left++;
      }

      while(right<n){
        ans.push_back(nums2[right]);
        right++;
      }
     
     for(int i=0;i<m+n;i++){
        nums1[i]=ans[i];
     }
    }
};
