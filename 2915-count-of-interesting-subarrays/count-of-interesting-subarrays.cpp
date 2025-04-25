class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt; // Hash map to count prefix % modulo frequencies
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1; // Initialize with prefix 0, so that full subarrays from 0 can be valid

        for (int i = 0; i < n; i++) {
            // Check if current element is a special element
            if (nums[i] % modulo == k)
                prefix++;

            // Find how many earlier prefixes match the needed condition
            int target = (prefix - k + modulo) % modulo;
            res += cnt[target];

            // Update the hash map with current prefix % modulo
            cnt[prefix % modulo]++;
        }

        return res;
    }
};
