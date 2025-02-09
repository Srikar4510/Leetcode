class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs=0,badpairs=0;
        unordered_map<int,int> diffCount;
        for(int pos=0;pos<nums.size();pos++){
            int diff = pos-nums[pos];
            goodPairs = diffCount[diff];
            badpairs += pos-goodPairs;
            diffCount[diff]++;
        }
        return badpairs;

    }
};