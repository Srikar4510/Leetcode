class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> cnt;
        unordered_set<int> st(nums.begin(),nums.end());
        int distinct = st.size();
        
        int left =0,res=0;
        for(int right=0;right<n;right++){
            cnt[nums[right]]++;

            while(cnt.size()==distinct){
                res += (n - right);


                cnt[nums[left]]--;

                if(cnt[nums[left]]==0){
                    cnt.erase(nums[left]);
                }
                left++;
            }
        }
        return res;
    }
};