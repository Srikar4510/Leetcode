class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int usedBits =0,windowStart =0,maxLength =0;

        for(int windowEnd=0;windowEnd<n;windowEnd++){
            //if there is overlapping 1 and 1 remove left most element
            //until there is no coflict
            while((usedBits & nums[windowEnd])!=0){
                //remove left most element from usedBits using XOR
                usedBits ^= nums[windowStart];
                windowStart++;
            }

            //if there is no conflict add current number to usedBits using OR
            //and store maxLength
            usedBits |= nums[windowEnd];
            maxLength = max(maxLength,windowEnd-windowStart+1);
        }
        return maxLength;
    }
};