class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;  // Step 1
        int totalLen = 0;                 // Step 2
        bool hasCenter = false;          // Step 3

        // Step 4: Build frequency map
        for (const string& word : words) {
            freq[word]++;
        }

        // Step 5: Process each word
        for (auto& [word, count] : freq) {
            string rev = string(word.rbegin(), word.rend());

            if (word != rev) {
                // Step 5.1: Handle asymmetric words
                if (freq.find(rev) != freq.end()) {
                    int pairs = min(count, freq[rev]);
                    totalLen += pairs * 4;
                    freq[word] -= pairs;
                    freq[rev] -= pairs;
                }
            } else {
                // Step 5.2: Handle symmetric words (like "gg")
                int pairs = count / 2;
                totalLen += pairs * 4;
                freq[word] -= pairs * 2;

                // Step 5.3: Can one unpaired symmetric word go to center?
                if (!hasCenter && freq[word] > 0) {
                    totalLen += 2;
                    hasCenter = true;
                }
            }
        }

        return totalLen; // Step 6: Final result
    }
};
