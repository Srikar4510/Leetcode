class Solution {
public:
//XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
//XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2
//if we perform the XOR of all the numbers of the array elements, we will be left with a single number
    int singleNumber(vector<int>& nums) {
        int xorr =0,n=nums.size();
        for(int i=0;i<n;i++){
            xorr = nums[i]^xorr;
        }
        return xorr;
    }
};