class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto x: mp){
            if(x.second % 2 != 0){
                return false;
            }
        }
        return true;
    }
};