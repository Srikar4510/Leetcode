class Solution {
public:
    vector<int> result;  // Stores the final sequence
    vector<bool> used;   // Tracks which numbers are used
    int size;            // Length of the sequence (2n - 1)

    bool backtrack(int index, int n) {
        // If we've placed all numbers, return true (we found a valid sequence)
        if (index == size) return true;

        // If this position is already filled, move to the next one
        if (result[index] != 0) return backtrack(index + 1, n);

        // Try placing numbers from largest to smallest (for lexicographical order)
        for (int num = n; num >= 1; num--) {
            // If this number is already used, skip it
            if (used[num]) continue;

            // If num == 1, we only place it once
            if (num == 1) {
                result[index] = 1;
                used[num] = true;
                if (backtrack(index + 1, n)) return true; // Move forward
                result[index] = 0; // Undo (backtrack)
                used[num] = false;
            }
            // If num > 1, check if we can place it at index and index + num
            else if (index + num < size && result[index + num] == 0) {
                result[index] = result[index + num] = num;
                used[num] = true;
                
                if (backtrack(index + 1, n)) return true; // Move forward

                // Undo (backtrack)
                result[index] = result[index + num] = 0;
                used[num] = false;
            }
        }

        return false; // No valid sequence found, backtrack
    }

    vector<int> constructDistancedSequence(int n) {
        size = 2 * n - 1;
        result.resize(size, 0);
        used.resize(n + 1, false);

        backtrack(0, n);
        return result;
    }
};
