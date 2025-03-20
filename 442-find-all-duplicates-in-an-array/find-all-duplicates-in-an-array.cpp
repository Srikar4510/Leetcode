class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(n+1,0);

        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==0){
                freq[nums[i]]++;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};