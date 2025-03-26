class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1); // Initialize result array with -1
        stack<int> st; // Monotonic decreasing stack to store indices

        // Traverse the array twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i % n]) {
                st.pop(); // Remove elements smaller than current
            }

            // If stack is not empty, store the top element as NGE
            if (!st.empty()) {
                nge[i % n] = nums[st.top()];
            }

            // Push current index onto stack
            st.push(i % n);
        }
        return nge;
    }
};
