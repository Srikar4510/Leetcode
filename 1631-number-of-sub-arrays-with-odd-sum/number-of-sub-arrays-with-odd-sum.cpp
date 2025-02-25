class Solution {
public:
//If two prefix sums have the same parity (both even or both odd), their difference will be even, meaning the subarray sum is even.
//If two prefix sums have different parity (one is even, the other is odd), their difference will be odd, meaning the subarray sum is odd.
//If prefixSum is even, it means the subarray sum from the start to the current index is even. To form an odd subarray, we need to subtract a previously seen odd prefix sum. So, we add the count of previously seen odd prefix sums to our answer.
//If prefixSum is odd, the subarray sum from the start to the current index is odd. To form another odd subarray, we need to subtract a previously seen even prefix sum. So, we add the count of previously seen even prefix sums to our answer

    int numOfSubarrays(vector<int>& arr) {
        int prefixSum;
        const int MOD = 1e9+7;
        // evenCount starts as 1 since the initial sum (0) is even
        int evenCount =1;
        int oddCount =0,ans=0;

        for(int num:arr){
            prefixSum += num;
            if(prefixSum %2==0){
                ans+=oddCount;
                evenCount++;
            }
            else{
                ans+=evenCount;
                oddCount++;
            }
            ans %= MOD;
        }
        return ans;
    }
};