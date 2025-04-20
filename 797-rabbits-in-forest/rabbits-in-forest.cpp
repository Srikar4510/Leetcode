class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int total =0;
        for(auto &[x,freq] : mp){
            int groupSize = x+1;
            int groupsNeeded = (freq+groupSize-1)/groupSize;
            total += groupsNeeded*groupSize;      
        }
        return total;
    }
};