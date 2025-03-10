class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }

        int xorr=0;
        for(auto x : mp){
            if(x.second==2){
                xorr ^= x.first;
            }
        }
    return xorr;
    }
};