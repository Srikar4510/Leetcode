class Solution {
public:
    // int lenLongestFibSubseq(vector<int>& arr) {
    //     int n = arr.size();
    //     int ans=0;
    //     unordered_set<int> st(arr.begin(),arr.end());
    //     for(int start=0;start<n;start++){
    //         for(int next=start+1;next<n;next++){
    //             int prev = arr[next];
    //             int curr = arr[start]+arr[next];
    //             int len = 2;
    //             while(st.find(curr)!=st.end()){
    //                 //prepare values for next iteration
    //                 int temp = curr;
    //                 curr += prev;
    //                 prev = temp;
    //                 ans= max(ans,++len);
    //             }
                
    //         }
            
    //     }
    //     return ans;
    // }

     int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
        // prev,curr
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        // Find all possible pairs that sum to arr[curr]
        for (int curr = 2; curr < n; curr++) {
            // Use two pointers to find pairs that sum to arr[curr]
            int start = 0;
            int end = curr - 1;

            while (start < end) {
                int pairSum = arr[start] + arr[end];

                if (pairSum > arr[curr]) {
                    end--;
                } else if (pairSum < arr[curr]) {
                    start++;
                } else {
                    // Found a valid pair, update dp
                    dp[end][curr] = dp[start][end] + 1;
                    maxLen = max(dp[end][curr], maxLen);
                    end--;
                    start++;
                }
            }
        }

        // Add 2 to include first two numbers, or return 0 if no sequence found
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};